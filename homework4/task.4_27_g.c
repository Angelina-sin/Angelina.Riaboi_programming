//task 4.27 g
#include <stdio.h>

int main(){
    double eps;
    printf("Enter epsilon (>0): ");
    scanf("%lf", &eps);

    double pi=0.0;
    double term;
    int k=0;
    int sign=1;

    do{
        term=sign*(4.0/(4*k+1)-2.0/(4*k+2)-1.0/(4*k+3));
        pi+=term;
        k++;
        sign=-sign;
    } while(term>eps||term<-eps);

    printf("Approximation of pi=%.10lf\n", pi);
    printf("Number of terms: %d\n", k);

    return 0;
}