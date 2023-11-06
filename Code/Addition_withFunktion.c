#include <stdio.h>
void ausgeben(int a, int b, int c){
    printf("%i plus %i ist gleich %i",a,b,c);
}

int addition(int a, int b){
    int c = a + b;
    return c;
}

main(){
    int x=6;
    int y=7;
    int s=addition(x,y);
    ausgeben(x,y,s);
}
