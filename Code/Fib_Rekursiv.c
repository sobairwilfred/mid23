#include <stdio.h>

//Fibonacci-Funktion durch Rekursiv realisiert.
int fib(int n){
    if (n<=1) return 1;
    else {
        return fib(n-1)+fib(n-2);
    } 

} 

main(){
    int n=10;//Eine natürliche Zahl eingeben, die Index in Fibonacci-Folge ist.
    printf("fib[%i]=%i\n", n, fib(n));//Die Fibonacci-Funktion aufrufen.
}


//Die ganze Folge zeigt. (kommentieren die main-Funktion, dann löschen untene "/*" und "*/".)
//p.s. auswählen und dann Kurzbefehl {Shift+Alt+A}

/* main(){
    for (int n=0; n<=10; n++){
        printf("fib[%i]=%i\n", n, fib(n));
    }   
} */