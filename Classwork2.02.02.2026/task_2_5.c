#include <stdio.h>
#include <math.h>

double Rosenbrock2d(double x, double y){
    return 100*(x*x-y)*(x*x-y)+(x-1)*(x-1);
}

int main(){
    printf("Rosenbrock 2D function:\n");
    printf("f(1,1)=%.6f\n", Rosenbrock2d(1, 1));
    printf("f(-1,1)=%.6f\n", Rosenbrock2d(-1, 1));
    printf("f(2,2)=%.6f\n", Rosenbrock2d(2, 2));

    return 0;
}