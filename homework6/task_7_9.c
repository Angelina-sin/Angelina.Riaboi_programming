//task 7.9 b
#include <stdio.h>

int main(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double a, min;

    printf("Enter a1: ");
    scanf("%lf", &a);
    min=a;

    for(int i=2; i<=n; i++){
        printf("Enter a%d: ", i);
        scanf("%lf", &a);

        if(a<min){
            min=a;
        }
    }

    printf("Minimum = %.2lf\n", min);

    return 0;
}