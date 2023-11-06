#include <stdio.h>

/*Output - Funktion*/
void ausgeben(int a, int b){
    printf("Die Fakultät von %i ist gleich %i\n",a,b);
}

/*Alternativ1: Goto und Label*/
int gotoLabel(int n){
    int ergebnis=n;
    int m=n;
    start:
        m--;
        ergebnis *= m;
        if (m<2) goto stop;
        else goto start;
    stop:
        return ergebnis; 
}

/*Alternativ2: Do-While-Schleife*/
int doWhile(int n){
    int ergebnis=n;
    int m=n;
    do{
        m--;
        ergebnis *= m;
    }while (m>1);
    return ergebnis;
}

/*Alternativ3: While-Schleife*/
int whileSchleife(int n){
    int ergebnis=n;
    int m=n;
    while (m>1)
    {
        m--;
        ergebnis *= m;
    }
    return ergebnis;
}

/*Alternativ4: For-Schleife*/
int forSchleife(int n){
    int ergebnis=n;
    for (int m=n-1;m>1;m--){
        ergebnis *= m;
    }
    return ergebnis;
}

main(){
    int n=9;//einfach hier eine positive ganzzählige Zahl eingeben
    ausgeben(n,gotoLabel(n));
    ausgeben(n,doWhile(n));
    ausgeben(n,whileSchleife(n));
    ausgeben(n,forSchleife(n));
}