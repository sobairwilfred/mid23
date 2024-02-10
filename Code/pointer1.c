#include <stdio.h>

int main(){
    int a = 5;
    int *zeiger = &a;
    /* int *zeiger;
    zeiger = &a; */

    int keinzeiger = a;

    printf("A = %i\n",a);
    printf("Addresse von A im Speicher: %p\n", &a);
    printf("Addresse von keinzeiger im Speicher: %p\n", &keinzeiger);
    printf("Addresse von Zeiger im Speicher: %p\n", &zeiger);
    printf("Wert von Zeiger im Speicher: %p\n", zeiger);
    printf("Zeiger: %i |Keinzeiger: %i\n", *zeiger,keinzeiger);

    //--Situation1--//

    a = 7;
    int *z=&a;
    int *x=&a;

    printf("Zeiger: %i |Keinzeiger: %i\n", *zeiger,keinzeiger);
    printf("%i, %i, %i\n",*z, *x, *zeiger);

    //--Situation2--//
    
    *z=3;
    printf("%i, %i, %i\n",*z, *x, *zeiger);

    //--Input--//

    printf("input: A = ");
    scanf("%i",&a);
    printf("output: A = %i\n", a); 
    printf("output: A = %i\n", *zeiger);
    printf("output: Addresse von A = %p\n", zeiger);
    printf("output: Addresse von A = %p\n", &a);
}
