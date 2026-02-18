#include <stdio.h>

int main() {
    double A,B,C;

    printf("Enter: A= ,B= ,C=\n");

    scanf("A=%lf, B=%lf C=%lf", &A, &B, &C);

    double arithmetic=(A+B+C)/3;
    double harmonic=3/(1/A+1/B+1/C);

    printf("Arithmetic=%.6f\n",arithmetic);
    printf("Arithmetic=%.6e\n",arithmetic);

    printf("Harmonic=%.6f\n",harmonic);
    printf("Harmonic=%.6e\n",harmonic);

    return 0;
}
