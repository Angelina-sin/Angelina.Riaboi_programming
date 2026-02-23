#include <stdio.h>
#include <math.h> 

// task2_17g
void task2_17g() {
    double x;
    double fx, dfx;

    printf("Enter x: ");
    scanf("%lf", &x);

    fx = atan(x);
    dfx = 1 / (1 + x*x);

    printf("f(x) = atan(%.2lf) = %.2lf\n", x, fx);
    printf("f'(x) = 1 / (1 + %.2lf^2) = %.2lf\n", x, dfx);
}

int main() {
    task2_17g();
    return 0;
}