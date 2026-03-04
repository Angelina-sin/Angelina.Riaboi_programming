// task 5.16. є

#include <stdio.h>
#include <math.h>

int main(){
    double x, eps;
    do{
        printf("Enter epsilon (>0):");
        scanf("%lf",&eps);
    }while(eps<=0);

    do{
        printf("Enter x (|x|<1):");
        scanf("%lf",&x);
    }while(fabs(x)>=1);

    double term=1.0;
    double sum=term;
    int n=1;

    while(fabs(term)>=eps){
        term*=-x; 
        sum+=term;
        n++;
    }

    printf("Approximation of 1/(1+%.6lf)=%.6lf using %d terms\n",x,sum,n);

    return 0;
}