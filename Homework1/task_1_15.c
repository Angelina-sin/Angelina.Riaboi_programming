#include <stdio.h>

int main() {
    double m,v,E;

    printf("Enter mass (kg) and velocity (m/s):");
    scanf("%lf %lf",&m,&v);

    E=0.5*m*v*v;

    printf("Kinetic energy = %.6f J\n",E);

    return 0;
}
