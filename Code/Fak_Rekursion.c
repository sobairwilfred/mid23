#include <stdio.h>

int fakRekursion(int n){
    if (n<=1)
        return 1;
    else 
        return n*fakRekursion(n-1);
}

int main(){
    int n=9;
    printf("%i! ist %i", n,fakRekursion(n));
}
