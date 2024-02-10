#include <stdio.h>

void ausgabe(int * array, int size) {
    for(int i = 0; i < size; i++) {
        printf("Addresse = %p\n", array);
        printf("Wert = %i\n", *array);
        array++;//different to: (*array)++;
    }
    printf("\n");
}

void geteiltDurch(int * array, int size, int divisor) {
    for (int i=0; i<size; i++){
        (*array)/=divisor;
        array++;
    }
}

int main() {
    int zahlen[] = { 42, 22, 50, 18, 34 };
    ausgabe(zahlen,5);
    printf("Geteilt durch %i\n", 2);
    geteiltDurch(zahlen,5,2);
    ausgabe(zahlen,5);
}
