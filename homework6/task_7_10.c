//task 7.10 e
#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int mas[100];

    for(int i=0; i<n; i++){
        printf("Enter a%d: ", i+1);
        scanf("%d", &mas[i]);
    }

    int count=0;

    for(int i=0; i<n; i++){
        int root=(int)sqrt(mas[i]);

        if(root*root==mas[i]&&root%2!=0){
            count++;
        }
    }

    printf("Number of squares of odd numbers = %d\n", count);

    return 0;
}
