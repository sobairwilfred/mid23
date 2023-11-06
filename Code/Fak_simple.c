#include <stdio.h>

main(){
/*Alternativ1: Goto und Label*/
    int n1=5;
    int erg1=n1;
    int m1=n1;
    start:
        m1--;
        erg1 *= m1;
        if (m1<2) goto stop;
        else goto start;
    stop:printf("Die Fakultät von %i ist gleich %i\n",n1,erg1);

/*Alternativ2: Do-While-Schleife*/
    int n2=6;
    int erg2=n2;
    int m2=n2;
    do{
        m2--;
        erg2 *= m2;
    }while(m2>1);
    printf("Die Fakultät von %i ist gleich %i\n",n2,erg2);

/*Alternativ3: While-Schleife*/
    int n3=7;
    int erg3=n3;
    int m3=n3;
    while(m3>1){
        m3--;
        erg3 *= m3;
    }
    printf("Die Fakultät von %i ist gleich %i\n",n3,erg3);

/*Alternativ4: For-Schleife*/
    int n4=8;
    int erg4=n4;
    for(int m4=n4-1; m4>1; m4--){
        erg4 *= m4;
    }
    printf("Die Fakultät von %i ist gleich %i\n",n4,erg4);
}