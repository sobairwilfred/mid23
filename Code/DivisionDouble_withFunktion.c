#include <stdio.h>
void ausgeben(int a, int b, double c){
    printf("%i durch %i ist gleich %f",a,b,c);
}

double quotient(int a, int b){
    double c = (double)a/(double)b;
    return c;
}

main(){
    int x=23;
    int y=7;
    double q=quotient(x,y);
    ausgeben(x,y,q);
}