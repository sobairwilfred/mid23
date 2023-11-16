#include <stdio.h>
//ggT-Funktion durch Schleife realisiert.
int ggt(int a, int b){
    //den kleineren Wert zwischen a und b finden.
    int kleiner;
    int ergebnis;
    if (a<b) kleiner=a;
    else kleiner=b;
    //mit 1 beginn, nehmen alle i, die (a mod i = 0) und (b mod i = 0),bis zu (i <=kleiner).
    for (int i=1; i<=kleiner; i++){
        if (a%i==0 && b%i==0){
            ergebnis=i;//den letzten Wert zu Ergebnis übergeben.
        }
    }
    return ergebnis;
}

main(){
    //zwei Zahn eingeben
    int a=11;
    int b=121;
    //ggT-Funktion aufrufen und dann ausdrucken.
    printf("ggT(%i,%i)=%i", a,b,ggt(a,b));
}