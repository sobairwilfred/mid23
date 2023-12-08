#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
   float re;
   float im;
} complex;

complex multiply(complex a, complex b) {
   complex erg;
   erg.re = a.re*b.re-a.im*b.im;
   erg.im = a.re*b.im+a.im*b.re;
   return erg;
}

float betrag(complex a) {
   float sq = a.re*a.re + a.im*a.im;
   return sqrt(sq);
}

complex plus(complex a, complex b) {
   complex ret;
   ret.re = a.re+b.re;
   ret.im = a.im+b.im;
   return ret;
}

//z_n+1 = z^2 + c, z0 = 0
//betrag(z_n) > 2

int mandelbrot_colorful(complex c) {
   complex last;
   last.re = 0;
   last.im = 0;
   for(int i = 0; i < 20; i++) {
      complex z = plus(multiply(last,last),c);
      last = z;
      if(betrag(last) > 2) break;
   }
   if(betrag(last) > 2) return 0;
   else {
      int color = (255*3)*(betrag(last)/2);
      if(betrag(last) > 2) color = 0;
   return color;
   }
}

int mandelbrot_blackwhite(complex c) {
   complex last;
   last.re = 0;
   last.im = 0;
   for(int i = 0; i < 20; i++) {
      complex z = plus(multiply(last,last),c);
      last = z;
      if(betrag(last) > 2) break;
   }
   int color = 255*3;
   if(betrag(last) > 2) color = 0;
   return color;
}

void drawImage_colorful(unsigned char pix[], int size, int width, int height, float minreal, float maxreal, float minim, float maxim) {
   
   float imdist = maxim - minim;
   float realdist = maxreal-minreal;
   long i = 0;
   for(int y = 0; y < height; y++) {
      //rastern: 0..height -> 0..1 -> minim..maxim
      float ir = (float)y/(float)(height-1) * imdist;
      ir = minim + ir;
      for(int x = 0; x < width; x++) {
         complex c;
         //rastern: 0..width -> 0..1 -> minreal..maxreal
         float fr = (float)x/(float)(width-1) * realdist;
         fr = minreal + fr;

         c.re = fr;
         c.im = ir;

         int erg = mandelbrot_colorful(c);
         int rot = erg; if(rot > 255) rot = 255;
         int gruen = erg-255; if(gruen < 0) gruen = 0; if(gruen > 255) gruen = 255;
         int blau = erg-510; if(blau < 0) blau = 0;
         pix[i*3] = rot;
         pix[i*3+1] = gruen;
         pix[i*3+2] = blau;
         i++;
      }
   }
}

void drawImage_blackwhite(unsigned char pix[], int size, int width, int height, float minreal, float maxreal, float minim, float maxim) {
   
   float imdist = maxim - minim;
   float realdist = maxreal-minreal;
   long i = 0;
   for(int y = 0; y < height; y++) {
      //rastern: 0..height -> 0..1 -> minim..maxim
      float ir = (float)y/(float)(height-1) * imdist;
      ir = minim + ir;
      for(int x = 0; x < width; x++) {
         complex c;
         //rastern: 0..width -> 0..1 -> minreal..maxreal
         float fr = (float)x/(float)(width-1) * realdist;
         fr = minreal + fr;

         c.re = fr;
         c.im = ir;

         int erg = mandelbrot_blackwhite(c);
         int rot = erg; if(rot > 255) rot = 255;
         int gruen = erg-255; if(gruen < 0) gruen = 0; if(gruen > 255) gruen = 255;
         int blau = erg-510; if(blau < 0) blau = 0;
         pix[i*3] = rot;
         pix[i*3+1] = gruen;
         pix[i*3+2] = blau;
         i++;
      }
   }
}

int main(){
   FILE *imageFile1;
   FILE *imageFile2;
   int x,y,pixel, height=400, width=800;
   int size = width*height*3;
   
   imageFile1=fopen("mandel_colorful.ppm","wb");
   imageFile2=fopen("mandel_blackwhite.ppm","wb");

   if(imageFile1==NULL){
      printf("ERROR: Cannot open output file");
      exit(EXIT_FAILURE);
   }

   if(imageFile2==NULL){
      printf("ERROR: Cannot open output file");
      exit(EXIT_FAILURE);
   }

   fprintf(imageFile1,"P6\n");               // P6 filetype
   fprintf(imageFile1,"%d %d\n",width,height);   // dimensions
   fprintf(imageFile1,"255\n");              // Max pixel

   fprintf(imageFile2,"P6\n");               // P6 filetype
   fprintf(imageFile2,"%d %d\n",width,height);   // dimensions
   fprintf(imageFile2,"255\n");              // Max pixel


   unsigned char pix[size];
   drawImage_colorful(pix, size, width, height, -2.0f, 1.0f, -1.0f, 1.0f);
   fwrite(pix,1,size,imageFile1);
   fclose(imageFile1);
   drawImage_blackwhite(pix, size, width, height, -2.0f, 1.0f, -1.0f, 1.0f);
   fwrite(pix,1,size,imageFile2);
   fclose(imageFile2);
}