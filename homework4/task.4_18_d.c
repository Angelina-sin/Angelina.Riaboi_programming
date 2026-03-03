//task.4.18.d
#include <stdio.h>

int main(){
    double x;
    unsigned k;

    printf("Enter a real number x: ");
    scanf("%lf", &x);

    printf("Enter k (k>=0): ");
    scanf("%u", &k);

    double term = 1.0;

    for(unsigned i=1; i<=k; i++){
        term *= x/i;
    }

    printf("x_%u=%lf\n", k, term);
    return 0;
}