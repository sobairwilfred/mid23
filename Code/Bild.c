//pc-pool - https://bytes.usc.edu/~saty/tools/PGMViewer/viewer.html
//eigenes Computer - installation of Extension: PBM/PPM/PGM Viewer

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawImage_vertical(unsigned char pix[], int size, int width, int height) {
    int i = 0;
    int rot = 0;
    int gruen = 0;
    int blau = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            /*
            i=0  pix[0]=R, pix[1]=G, pix[2]=B,
            i=1  pix[3]=R, pix[4]=G, pix[5]=B,
            i=2  pix[6]=R, pix[7]=G, pix[8]=B,
              ...
            */
            pix[i*3] = rot;
            pix[i*3+1] = gruen;
            pix[i*3+2] = blau;
            i++;
        }
        /*Graustufenerhöhung in der Richtong von "height"*/
        rot++;
        gruen++;
        blau++;
    }
}

void drawImage_horizon(unsigned char pix[], int size, int width, int height) {
    int i = 0;
    int rot = 0;
    int gruen = 0;
    int blau = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            pix[i*3] = rot;
            pix[i*3+1] = gruen;
            pix[i*3+2] = blau;
            i++;
            rot++;
            rot %= 255;//width=500>255, deswegen berechnet modulo, um width 255 nicht überschreitet.
            gruen++;
            gruen %= 255;//width=500>255, deswegen berechnet modulo, um width 255 nicht überschreitet.
            blau++;
            blau %= 255;//width=500>255, deswegen berechnet modulo, um width 255 nicht überschreitet.
        }
        rot = 0;
        gruen = 0;
        blau = 0;
    }
}


int main() {
   FILE *imageFile1;//eine File definieren
   FILE *imageFile2;
   int x,y,pixel, height=250, width=500;
   int size = width*height*3;
   
   imageFile1=fopen("image_vertical.ppm","wb");//fopen: FILE *fopen(const char *filename, const char *mode)
   imageFile2=fopen("image_horizon.ppm","wb");
   //image.pmm:file name
   //wb:file mode:Öffnen oder erstellen eine neue Binärdatei nur zum Schreiben; nur das Schreiben von Daten ist zulässig

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
   drawImage_vertical(pix, size, width, height);
   fwrite(pix,1,size,imageFile1); //fwrite(const void *ptr, size, nmemb, FILE *stream)
   drawImage_horizon(pix, size, width, height);
   fwrite(pix,1,size,imageFile2);
   /*
   ptr: Dies ist ein Zeiger auf das Array der zu schreibenden Elemente
   size: Dies ist die Größe jedes zu schreibenden Elements in Bytes
   nmemb: Dies ist die Anzahl der Elemente, jedes Element hat die Größe Bytes
   stream: Dies ist ein Zeiger auf ein FILE-Objekt, das einen Ausgabestream angibt
   */
   fclose(imageFile1);//fclose:Stream-Stream schließen. Alle Puffer leeren.
   fclose(imageFile2);
}