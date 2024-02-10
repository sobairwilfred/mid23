#include <stdio.h>
void ausgeben(int a, int b, int c, int d){
    printf("%i durch %i ist gleich %i rest %i",a,b,c,d);
}

int quotient(int a, int b){
    int c = a/b;
    return c;
}

int modulo(int a, int b){
    int d = a%b;
    return d;
}

int main(){
    int x=23;
    int y=7;
    int q=quotient(x,y);
    int m=modulo(x,y);
    ausgeben(x,y,q,m);
}
