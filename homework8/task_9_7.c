//task 9.7
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_power_of_two(int n){
    if(n<1) return false;
    while(n%2==0) n/=2;
    return n==1;
}

bool is_power_of_three(int n) {
    if(n<1) return false;
    while(n%3==0) n/=3;
    return n==1;
}

int main(){
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int*arr=(int*)malloc(n*sizeof(int));
    if(!arr) {
        printf("memory allocation failed\n");
        return 1;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int count_two=0, count_three=0;
    for(int i=0; i<n; i++){
        if(is_power_of_two(arr[i])) count_two++;
        if(is_power_of_three(arr[i])) count_three++;
    }

    printf("powers of 2: %d\n", count_two);
    printf("powers of 3: %d\n", count_three);

    free(arr);
    return 0;
}