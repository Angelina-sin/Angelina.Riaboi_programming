//task 7.10 e
#include <stdio.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int a;
    int count=0;

    for(int i=1; i<=n; i++){
        printf("Enter a%d: ", i);
        scanf("%d", &a);

        if(a % 2!=0){   
            count++;       
        }
    }

    printf("Number of squares of odd numbers = %d\n", count);

    return 0;
}