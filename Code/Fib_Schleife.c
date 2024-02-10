#include <stdio.h>
//Fibonacci-Funktion durch Schleife realisiert.
int fib(int n){
    int a=1;//fib[0]=1
    int b=1;//fib[1]=1
    int c;//fib[n]
    for (int i=2;i<=n;i++){
        c=a+b;//fib[n]=fib[n-1]+fib[n-2]
        /*Nach einer Schleife, a und b eine Stelle hinter schieben. 
        z.B. original a ist fib[0], b ist fib[1], 
        nach erster Schleife ist a=fib[1], b=fib[2]*/
        a=b;
        b=c;
    }
    return c;
}

//Nur mit bestimmtem Index zeigt. (kommentieren die main-Funktion, dann löschen untene "/*" und "*/".)
//p.s. auswählen und dann Kurzbefehl {Shift+Alt+A}

/* main(){
    int n=20;//Eine natürliche Zahl eingeben, die Index in Fibonacci-Folge ist.
    printf("fib[%i]=%i\n",n,fib(n));//Die Fibonacci-Funktion aufrufen.
} */


int main(){
    for (int n=0; n<=20; n++){
        printf("fib[%i]=%i\n", n, fib(n));
    }   
}
