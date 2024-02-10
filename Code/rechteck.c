#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}punkt;

typedef struct{
    //diagonal
    punkt v1;
    punkt v2;
}rechteck;

double flaeche(rechteck r){
    double height = r.v2.y-r.v1.y;
    double width = r.v2.x-r.v1.x;
    double area = height*width;
    return area;
}

int main(){
    punkt p1;
    p1.x = 2;
    p1.y = 1;

    punkt p2;
    p2.x = 7;
    p2.y = 4;

    rechteck r1;
    r1.v1=p1;
    r1.v2=p2;

    double f = flaeche(r1);
    printf("Flaech = %.2f\n", f);
}
