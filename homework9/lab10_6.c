#include <stdio.h>

#define MAX 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int n;
    Point p[MAX];
} Polygon;

void inputPolygon(Polygon *poly) {
    printf("Enter number of points: ");
    scanf("%d", &poly->n);

    while (poly->n < 1 || poly->n > MAX) {
        printf("Error! Enter number from 1 to %d: ", MAX);
        scanf("%d", &poly->n);
    }

    for (int i=0; i<poly->n; i++) {
        printf("Enter point %d (x y): ", i+1);
        scanf("%lf %lf", &poly->p[i].x, &poly->p[i].y);
    }
}

void outputPolygon(Polygon poly) {
    printf("Polygon points:\n");

    for (int i=0; i<poly.n; i++) {
        printf("Point %d: (%.2lf, %.2lf)\n",
               i+1,
               poly.p[i].x,
               poly.p[i].y);
    }
}

int main() {
    Polygon poly;

    inputPolygon(&poly);
    outputPolygon(poly);

    return 0;
}