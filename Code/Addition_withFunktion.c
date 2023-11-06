#include <stdio.h>
void ausgeben(int a, int b, int c){
    printf("%i plus %i ist gleich %i",a,b,c);
}

int addition(int a, int b){
    int c = a + b;
    return c;
}

main(){
    int a=6;
    int b=7;
    int c=addition(a,b);
    ausgeben(a,b,c);
}