#include <stdio.h>

int main() {
    double a,b;

    printf("Enter two numbers:");
    scanf("%lf %lf",&a,&b);

    double arithmetic=(a+b)/2;
    double harmonic=(2*a*b)/(a+b);

    printf("Arithmetic mean=%.6f\n",arithmetic);
    printf("Arithmetic mean=%.6e\n",arithmetic);

    printf("Harmonic mean=%.6f\n",harmonic);
    printf("Harmonic mean=%.6e\n",harmonic);

    return 0;
}