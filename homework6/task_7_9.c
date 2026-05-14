//task 7.9 b
#include <stdio.h>

int main(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double mas[100];

    for(int i=0; i<n; i++){
        printf("Enter a%d: ", i+1);
        scanf("%lf", &mas[i]);
    }
    double min = mas[0];

    for(int i = 1; i < n; i++){
        if(mas[i] < min){
            min = mas[i];
        }
    }
    printf("Minimum = %.2lf\n", min);

    return 0;
}
