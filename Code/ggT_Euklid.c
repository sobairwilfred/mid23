#include <stdio.h>
//ggT-Funktion durch Euklid realisiert.
int ggt(int a, int b) {
    int iterationen = 0;//zählen wie viel iterationen durchgeführt.
    while(b != 0) {
        int r = a % b;
        printf("%i mod %i = %i\n",a,b,r);
        /*Nach Euklidischer_Algorithmus, in der nächsten Schleife:
        b (Dividende in dieser Schleife) wird Divisor;
        r (Modulo in dieser Schleife) wird Dividend */
        a = b;
        b = r;//r zu b übergeben, wenn r=0, dann b=0, Schleife beendet.    
        iterationen++;
    }
    printf("iterationen: %i\n",iterationen);
    return a;
}

int main() {
    printf("ggT(12,3) = %i\n",ggt(12,3));
    printf("ggT(11,121) = %i\n",ggt(11,121));
    printf("ggT(40,16) = %i\n",ggt(40,16));
}