#include <stdio.h>

int method(int a){
    printf("*Method begins with input=%i\n", a);
    a+=1;
    if (a<5){
        method(a);
    }else {
        printf("!!! Input >= %i !!!\n", a);
    }
    printf("*Method ends with output=%i\n", a);
    return a;
}

int main(){
    printf("Main Program Starts!\n");
    int eingeben=0;
    method(eingeben);
    printf("Main Program Ends!\n");
} 


//intuiv zeigt darunter:

/*
    ******Rekurs1 start
        ******Rekurs2 start
            ******Rekurs3 start
            ******Rekurs3 end
        ******Rekurs2 end
    ******Rekurs1 end
*/
