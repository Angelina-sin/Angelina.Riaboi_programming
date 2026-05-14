#include <stdio.h>
#include <math.h> 

// Task 1
void task1(){
    double a;
    printf("Enter a real number: ");
    scanf("%lf", &a);

    int n=0;
    double s=0;

    while(s<=a){
        n++;
        s+=1.0/n;
    }

    printf("n=%d\n", n);
}

// Task 2
unsigned long long fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    unsigned long long a=0, b=1, fib_n;
    for(int i=2; i<=n; i++){
        fib_n=a+b;
        a=b;
        b=fib_n;
    }
    return fib_n;
}
int fibonacci_less(double a){
    int n=1;
    unsigned long long a_val=0, b_val=1, fib_n=1;
    while (fib_n<a){
        n++;
        fib_n=a_val+b_val;
        a_val=b_val;
        b_val=fib_n;
    }
    return n-1;
}
unsigned long long sum_fibonacci(int n){
    unsigned long long a=0, b=1, sum=0;
    while(b<n){
        sum+=b;
        unsigned long long temp=a+b;
        a=b;
        b=temp;
    }
    return sum;
}

void task2(){
    int n;
    printf("Enter the index of the Fibonacci number: ");
    scanf("%d", &n);
    if(n<0){
        printf("Index cannot be negative.\n");
        return;
    }
    unsigned long long fib_n=fibonacci(n);
    printf("The %d-th Fibonacci number is: %llu\n", n, fib_n);

    double a;
    printf("Enter a threshold value: ");
    scanf("%lf", &a);
    int index=fibonacci_less(a);
    printf("The index of the Fibonacci number less than %.2lf is: %d\n", a, index);

    unsigned long long sum=sum_fibonacci(n);
    printf("The sum of the first %d Fibonacci numbers is: %llu\n", n, sum);
}

// Task 3
int collatz_steps(int n){
    int a=n;
    int steps=0;

    while(a!=1){
        if(a%2==0)
            a=a/2;
        else
            a=3*a+1;

        steps++;
    }
    return steps;
}
void task3(){
    int max_steps=0;
    int number_with_max=1;

    for(int k=1; k<1000; k++){
        int steps=collatz_steps(k);

        if(steps>max_steps){
            max_steps=steps;
            number_with_max=k;
        }
    }

    printf("Number with maximum steps (<1000): %d\n", number_with_max);
    printf("Maximum steps: %d\n", max_steps);
}

// Task 4
void task4(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    double p=1, fact=1;
    for(int i=1; i<=n; i++){
        fact*=1.0/i; 
        p*=(1+fact); 
    }
    printf("Value of p: %.6lf\n", p);
}

void task4b(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    double p=1+0.5, term=0.5;
    for(int i=2; i<=n; i++){
        term*=-i*i/(i-1)/(i-1)/2; 
        p*=(1+term); 
    }
    printf("Value of p: %.6lf\n", p);
}

// Task 5
void task5(){
    int x1,x2,x3,x;
    int i=3;
    x1=x2=x3=-99;
    printf("Enter a positive integer: "); 
    scanf("%d", &x); 

    do{
        x=x1+x3+100;
        x1=x2;
        x2=x3;
        x3=x;
        i++;
        printf("x_%d = %d\n", i, x);
    }while (x<=0);

    printf("The first positive integer in the sequence is x%d=%d\n", i, x);    
}

// Task 6
void task6a() {
    int n;
    double b;
    printf("Task 6a: Enter n and b: ");
    scanf("%d %lf", &n, &b);

    double bk=b;
    for(int k=1; k<=n; k++){
        bk=b+1.0/bk;
    }

    printf("b_%d=%.6lf\n", n, bk);
}

void task6b() {
    int n;
    printf("Task 6b: Enter n: ");
    scanf("%d", &n);

    double lam=4*n+2; 
    for(int k=1; k<=n; k++){
        lam=4*(n-k)+2+1.0/lam;
    }

    printf("lambda_%d=%.6lf\n", n, lam);
}

void task6c() {
    int n;
    printf("Task 6c: Enter n: ");
    scanf("%d", &n);

    double x=2;
    for(int k=n; k>=1; k--){
        if(k%2==0) 
            x=2+1.0/x;
        else
            x=1+1.0/x;
    }

    printf("x_%d=%.6lf\n", n, x);
}

// Task 7
void task7(){

    double a1,a2,b1,b2,a,b,sum,power2=4;

    a1=0;
    a2=1;
    b1=1;
    b2=0;

    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    if (n<0){
        printf("Number of iterations cannot be negative.\n");
        return;
    }
    else if (n==0){
        printf("After 0 iterations: a=%6lf, b=%6lf\n sum=%6lf", 0,0,0);
        return;
    }
    else if (n==1){
        sum=2/(a1+b1);
        printf("After 1 iteration: a=%6lf, b=%6lf\n sum=%6lf", a1,b1,sum);
        return;
    }
    else if (n==2){
        sum=4/(a2+b2)+2/(a1+b1);
        printf("After 2 iterations: a=%6lf, b=%6lf\n sum=%6lf", a2,b2,sum);
        return;
    }
    else{
        sum=4/(a2+b2)+2/(a1+b1);
        for(int k=3; k<=n; k++){
            a=a2/k+a1*b1;
            b=b2+a2;
            a1=a2;
            a2=a;
            b1=b2;
            b2=b;
            power2*=4;
            sum+=power2/(a+b);
        }
    }
    printf("After %d iterations: a=%6lf, b=%6lf\n sum=%6lf", n,a,b,sum);
}

// Task 8
double tailor_exp(double x, double eps){
    double term=1;
    double sum=term;
    int n=1;
    while(fabs(term)>=eps){
        term*=x/n;
        sum+=term;
        n++;
    }
    return sum;
}

double phi_exp(double x, double eps){
    double term=x*x*x/3;
    double sum=x+term;
    int n=1;
    while(fabs(term)>=eps){
        term*=-x*x*(2*n+1)/(2*n+3)/(2*n)/(2*n+1);
        sum+=term;
        n++;
    }
    return sum;
}

void task8(){
    double eps, x;
    do{
        printf("Enter a positive number for epsilon: ");
        scanf("%lf", &eps);
    } while(eps<=0);
    
    printf("Enter a number for x: ");
    scanf("%lf", &x);
    double exp_approx=tailor_exp(x, eps);
    double phi_approx=phi_exp(x, eps);
    printf("Approximation of exp(%.2lf): %.6lf\n", x, exp_approx);
    printf("Approximation of phi(%.2lf): %.6lf\n", x, phi_approx);
}

int main() {
    
    task1();
    task2();
    task3();
    task4();
    task4b();
    task5();
    task6a();
    task6b();
    task6c();
    task7();
    task8(); 

    return 0;
}