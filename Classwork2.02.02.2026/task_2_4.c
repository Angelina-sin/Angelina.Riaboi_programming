#include <stdio.h>

// a)
 double task2_4_func1(double x){
     double y = x*x+1;
     return y*y;
 }

// в)y=x^5+5x^4+10x^3+10x^2+5x+1
double task2_4_func3(double x){
    double y=(((x+5)*x+10)*x+10)*x+5;
    y=y*x+1;
    return y;
}

int main(){
    double x,y;
    printf("Enter x for task2_4_func1 :");
    scanf("%lf",&x);
    y = task2_4_func1(x);
    printf("Result y(task2_4_func1)=%6f\n", y);

    printf("Enter x for task2_4_func3 :");
    scanf("%lf",&x);
    y = task2_4_func3(x);
    printf("Result y(task2_4_func3)=%6f\n", y);
}
