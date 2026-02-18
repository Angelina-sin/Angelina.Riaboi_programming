#include <stdio.h>

int main() {
    double a,b;

    printf("Enter first number: ");
    scanf("%lf",&a);

    printf("Enter second number: ");
    scanf("%lf",&b);

    double difference = a-b;
    double product = a*b;

    printf("Difference=%.6f\n",difference);
    printf("Product=%.6f\n",product);

    return 0;
}
