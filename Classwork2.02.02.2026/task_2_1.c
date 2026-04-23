// task 2.1, 2.2, 2.3
#include <stdio.h>
#include <math.h>

double cosh_calculate(double x){
    return (exp(x)+exp(-x))/2.0;
}

double hypothenous(double a, double b){
    return sqrt(a*a+b*b);
}

double area_heron(double a, double b, double c){
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    double x;
    printf("Enter x:");
    scanf("%lf",&x);
    double cosh_x=cosh(x);
    double cosh_x2=cosh_calculate(x);
    printf("Cosh(x): %.6f\n", cosh_x);
    printf("Cosh(x) calculated manually: %.6f\n\n", cosh_x2);

    double a1, b1;
    printf("Enter a, b:");
    scanf("%lf %lf",&a1,&b1);
    double hyp = hypothenous(a1, b1);
    printf("Hypothenous: %.6f\n\n",hyp);

    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double area = area_heron(a,b,c);
    printf("Area by Heron's formula: %.6f\n",area);

    return 0;
}