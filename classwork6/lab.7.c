#include <stdio.h>
#include <math.h> 

//Task 1
void task1(){
    int mas[] = {1,2,3,4,5};
    int n=sizeof(mas)/sizeof(mas[0]);
    double a;
    int count=0;

    printf("Enter a real number: ");
    scanf("%lf", &a);

    for(int i=0; i<n; i++){
        if(mas[i]<a)
            count++;
    }

    printf("Count of elements less than %.2lf = %d\n", a, count);
}

// Task 2
void task2(){
    int mas[]={5,112,4,3};
    int n = sizeof(mas)/sizeof(mas[0]); 

    printf("Reverse order of the array: ");

    for(int i=n-1; i>=0; i--){
        printf("%d ", mas[i]);
    }

    printf("\n");
}

// Task 3
#define N 10

int input_array_double(double ar[]){
    for(int i=0; i<N; i++){
        printf("Input ar[%d] = ", i);
        scanf("%lf", &ar[i]);
    }
    return N;
}

double summarry(double ar[]){
    double y=0;

    for(int i=0; i<N;i++ ){
        if(ar[i]>exp(1)){
            y+=ar[i];
        }
    }

    return y;
}

void task3(){
    double mas[N];

    input_array_double(mas);

    double y=summarry(mas);

    printf("y = %.2lf\n", y);
}


// Task 4
int input_array_int(int ar[], int n){
    for(int i=0; i<n; i++){
        printf("Input ar[%d] = ", i);
        scanf("%d", &ar[i]);
    }
    return n;
}

int max_array(int ar[], int n){
    int maximum = ar[0];

    for(int i=1; i<n; i++){
        if(ar[i] > maximum){
            maximum = ar[i];
        }
    }
    return maximum;
}

void task4(){
    int mas[5];

    int k=input_array_int(mas, 5);

    int maximum=max_array(mas, k);

    printf("Maximum = %d\n", maximum);
}


//Task 5
#define MAX 50

void task5(){
    int mas[MAX];
    int n=0;

    printf("Enter natural numbers (0 to stop):\n");

    while(n<MAX){
        scanf("%d", &mas[n]);

        if(mas[n]==0)
            break;

        n++;
    }

    int even=0;
    int odd=0;

    for(int i=0;i<n;i++){
        if(mas[i]%2==0)
            even++;
        else
            odd++;
    }

    printf("Even elements = %d\n", even);
    printf("Odd elements = %d\n", odd);
}


int main() {
    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}