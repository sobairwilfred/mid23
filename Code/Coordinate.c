#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} punkt;

typedef struct {
    punkt start;
    punkt end;
} linie;

typedef struct{
    punkt v1;
    punkt v2;
    punkt v3;
}dreieck;

double distance(punkt p1, punkt p2) {
    double dx=p1.x-p2.x;
    double dy=p1.y-p2.y;
    double L=sqrt(pow(dx,2)+pow(dy,2));
    return L;
}

double area(dreieck d) {
    double l1 = distance(d.v1,d.v2);
    double l2 = distance(d.v2,d.v3);
    double l3 = distance(d.v3,d.v1);
    double gama = acos((l1*l1+l2*l2-l3*l3)/(2*l1*l2));
    double S = sin(gama)*l1*l2/2;
    return S;
} 

int main() {
    punkt a;
    a.x = 2;
    a.y = 5;
    punkt b;
    b.x = 4;
    b.y = 2;
    punkt c;
    c.x = 5;
    c.y = 3;
    dreieck tri;
    tri.v1 = a; 
    tri.v2 = b;
    tri.v3 = c;

    printf("Punkt A: X=%i Y=%i\n",a.x,a.y);
    printf("Punkt B: X=%i Y=%i\n",b.x,b.y);
    printf("Entfernung von A zu B: %.2f\n",distance(a,b));
    printf("Flaeche vom Dreieck: %f\n",area(tri));
}
