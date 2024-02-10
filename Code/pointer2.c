#include <stdio.h>

void dividiere(int a, int b, int * erg, int * rest) {
    *erg=a/b;
    *rest=a%b;
}

int main() {
    int a = 10;
    int b = 3;
    int ergebnis = 0;
    int rest = 0;

    printf("A = ");
    scanf("%i", &a);
    printf("B = ");
    scanf("%i", &b);

    dividiere(a,b,&ergebnis,&rest);
    printf("A/B = %i geteilt durch %i ist %i Rest %i\n", a, b, ergebnis, rest);

}
