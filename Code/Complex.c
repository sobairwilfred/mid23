#include <stdio.h>
#include <math.h>

typedef struct{
    double re; //Realteil
    double im; //Imagenärteil
}complex;

complex addition(complex c1, complex c2){
    //[Addition] z1+z2 = (re1+re2)+(im1+im2)*i
    double re_add=c1.re+c2.re;
    double im_add=c1.im+c2.im;
    complex add;
    add.re = re_add;
    add.im = im_add;
    return add;
}

complex multiply(complex c1, complex c2){
    //[Multiplikation] z1*z2 = (re1*re2-im1*im2)+(re1*im2+re2*im1)*i
    complex mul;
    mul.re = c1.re*c2.re-c1.im*c2.im;
    mul.im = c1.re*c2.im+c1.im*c2.re;
    return mul;
}

double betrag(complex c){
    //[Betrag] |z| = sqrt(re^2+im^2)
    double z = sqrt(c.re*c.re+c.im*c.im);
    return z;
}

main(){
    complex x;
    x.re = 6;
    x.im = 7;
    complex y;
    y.re = 3;
    y.im = 1;

    complex add = addition(x,y);
    complex mul = multiply(x,y);
    double betrag_x=betrag(x);
    double betrag_y=betrag(y);

    printf("X=%.1f+%.1f*i\n",x.re,x.im);
    printf("Y=%.1f+%.1f*i\n",y.re,y.im);
    printf("X+Y=%.1f+%.1f*i\n",add.re,add.im);
    printf("X*Y=%.1f+%.1f*i\n",mul.re,mul.im);
    printf("|X|=%.1f\n",betrag_x);
    printf("|Y|=%.1f\n",betrag_y);
}