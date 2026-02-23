#include <stdio.h>
#include <math.h> 

void task2_10() {
    double a, b, c;
    double A, B, C;
    double A_deg, B_deg, C_deg;

    printf("Enter sides a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a+b<=c || a+c<=b || b+c<=a) {
        printf("Not a valid triangle\n");
        return;
    }

    A = acos((b*b + c*c - a*a) / (2*b*c));
    B = acos((a*a + c*c - b*b) / (2*a*c));
    C = acos((a*a + b*b - c*c) / (2*a*b));

    A_deg = A * 180 / M_PI;
    B_deg = B * 180 / M_PI;
    C_deg = C * 180 / M_PI;

    printf("Angles in degrees: A=%.2lf, B=%.2lf, C=%.2lf\n", A_deg, B_deg, C_deg);
}
int main() {
    task2_10();
    return 0;
}