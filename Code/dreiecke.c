#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} punkt;

typedef struct {
    punkt a, b, c;
} dreieck;

float laenge(punkt p1, punkt p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

float flaeche(dreieck d) {
    double a = laenge(d.a, d.b);
    double b = laenge(d.b, d.c);
    double c = laenge(d.c, d.a);
    double g = acos((a*a+b*b-c*c)/(2*a*b));
    double h = b * sin(g);
    double f = a*h/2;
    printf("Gamma: %f, Hoehe: %f, Flaeche: %f\n",g,h,f);
    return f;
}

int main() {
    srand(42);
    dreieck alleDreiecke[20];
    for(int i = 0; i < 20; i++) {
        punkt a, b, c;
        a.x = rand() % 10;
        a.y = rand() % 10;
        do { b.x = rand() % 10; } while(b.x == a.x);
        do { b.y = rand() % 10; } while(b.y == a.y);
        do { c.x = rand() % 10; } while(c.x == b.x || c.x == a.x);
        do { c.y = rand() % 10; } while(c.y == b.y || c.y == a.y);
        dreieck d;
        d.a = a;
        d.b = b;
        d.c = c;
        alleDreiecke[i] = d;
    }

    for(int i = 0; i < 20; i++) {
        dreieck d = alleDreiecke[i];
        printf("Dreieck P(%i,%i)-Q(%i,%i)-R(%i,%i) - Flaeche: %.2f\n",
            d.a.x,d.a.y,d.b.x,d.b.y,d.c.x,d.c.y,flaeche(d));
    }
}