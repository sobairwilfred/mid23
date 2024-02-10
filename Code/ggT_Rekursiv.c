#include <stdio.h>
//ggT-Funktion durch Rekursiv realisiert.
int ggt_r(int a, int b, int kleiner){
    if (kleiner<=1) return 1;
    /*mit "kleiner" beginn, wenn (a mod kleiner = 0) und (b mod kleiner = 0), gibt "kleiner" zurück,
    ansonst "kleiner"-1, und dann noch mal ggt_r aufrufen.*/
    if (a%kleiner==0 && b%kleiner==0) return kleiner;
    else return ggt_r(a,b,kleiner-1);
}

int ggt(int a, int b){
    int kleiner;
    if (a<b) kleiner=a;
    else kleiner=b;
    return ggt_r(a,b,kleiner);
}

int main(){
    printf("ggT(%i,%i)=%i", 15,12,ggt(15,12));
}
