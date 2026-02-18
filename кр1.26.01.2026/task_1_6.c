//задача 1.6
#include <stdio.h>

int main()
{
    double celsius, farengate;
    printf("Iput farengate:");
    scanf("%lf",&farengate);
    celsius=(farengate-32)*5/9;
    printf("celius=%g",celsius);
}