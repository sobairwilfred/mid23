#include <stdio.h>

int summe(int array[], int length) {
    int summe = 0;
    for(int i = 0; i < length; i++) {
        printf("Das %ite Element von a ist %i.\n",i,array[i]);
        summe += array[i];
    }
    printf("Die Summe aller Elemente ist %i.\n",summe);
    return summe;
}

double durchschnitt(int array[], int length) {
    double dsn=0;
    double s=(double)summe(array,length);
    dsn=s/(double)length;
    printf("Der Durchschnitt aller Elemente ist %.2f.\n",dsn);
    return dsn;
}

int max(int array[], int length){
    int max=array[0];
    for(int i=1; i<length; i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    printf("The max value of array is %i.\n",max);
    return max;
}

int min(int array[], int length){
    int min=array[0];
    for(int i=1; i<length; i++){
        if(array[i]<min){
            min=array[i];
        }
    }
    printf("The min value of array is %i.\n",min);
    return min;
}

void sort_auf_up(int array[], int length) {
    //Ausgabe der Zahlen in aufsteigender Reihnfolge
    int i, j, tmp; 
    for (i = 1; i < length; i++) {
        for (j = 0; j < length - i; j++) {
            if (array[j] > array[j+1]) { 
                tmp = array[j]; 
                array[j] = array[j+1]; 
                array[j+1] = tmp; 
            } 
        } 
    }
    for(int i = 0; i < length; i++) {
        printf("%i ",array[i]);
    }
    printf("\n");
}

void sort_auf_down(int array[], int length) {
    //Ausgabe der Zahlen in aufsteigender Reihnfolge
    int i, j, tmp; 
    for (i = 0; i < length; i++) {
        for (j = length-1; j > i; j--) {
            if (array[j] < array[j-1]) { 
                tmp = array[j]; 
                array[j] = array[j-1]; 
                array[j-1] = tmp; 
            } 
        } 
    }
    for(int i = 0; i < length; i++) {
        printf("%i ",array[i]);
    }
    printf("\n");
}

void sort_ab(int array[], int length){
    //Ausgabe der Zahlen in absteigender Reihnfolge
    int i,j,tmp;
    for(i=1;i<length;i++){
        for(j=0;j<length-1;j++){
            if(array[j]<array[j+1]){
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
    for(int i = 0; i < length; i++) {
        printf("%i ",array[i]);
    }
    printf("\n");
}


main() {
    int LENGTH = 6;
    int a[6] = { 2, 4, 6, 3, 1, 5 };
    a[2] = 100;
    summe(a, LENGTH);
    durchschnitt(a,LENGTH);
    //existiert Funktionen für LENGTH
    int l= sizeof(a)/sizeof(a[0]);
    printf("Length:(%i/%i)=%i\n", sizeof(a),sizeof(a[0]),l);
    max(a,LENGTH);
    min(a,LENGTH);
    sort_auf_up(a,LENGTH);
    sort_auf_down(a,LENGTH);
    sort_ab(a,LENGTH);
}
  