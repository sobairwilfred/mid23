#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y, z;
} punkt;

typedef struct {
    punkt mitte;
    punkt rand;
} kugel;

/* typedef struct {
    punkt mitte;
    float radius;
} kugelr; */

float distanz(punkt a, punkt b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

float volumen(float r) {
    return 4.0f/3.0f * r * r * r * M_PI;
}

int main() {
    punkt p1, p2;
    p1.x = 3; p1.y = 3; p1.z = 3;
    p2.x = 5; p2.y = 4; p2.z = 5;
    kugel k1;
    k1.mitte = p1;
    k1.rand = p2;
    printf("Volumen: %.2f\n",volumen(distanz(k1.mitte, k1.rand)));
}