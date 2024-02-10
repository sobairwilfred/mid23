#include <stdio.h>

int fak(int n){
    int ergebnis=n;
    for(int m=2; m<n; m++){
        ergebnis *= m;
    }
    printf("%i \t %i\n",n,ergebnis);
    return ergebnis;
}

int main(){
    for(int ex=0; ex<=1; ex++){
        printf("%i \t %i\n",ex,1);
    }   
    for(int i=2; i<25; i++){
        fak(i);
    }
}

/* 
Zusammenfassen:

Spätestens ab 14! scheint das Programm offenbar nicht mehr zu funktionieren, d.h. falsche 
Ergebnisse zu liefern. Dies liegt an der oberen Grenze des Datentyps “int”. Dieser liegt bei 
2.147.483.647 also knapp über 2 Mrd. Um mit größeren Zahlen zu rechnen kann einerseits dass 
Vorzeichen weggelassen werden („unsigned int“), ein größerer Datentyp genutzt werden oder 
beides. Das Maximum stellt dabei der Datentyp „unsigned long long“ dar. 

from Dr. Sebastian Götz
*/
