#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Task 1
//a)
void task1_a(unsigned n){
    unsigned d1=n%10;
    unsigned d2=(n/10)%10;
    unsigned d3=n/100;

    printf("Digits: %u %u %u\n",d1,d2,d3);
}

//b) 
void task1_b(unsigned n){
    unsigned d1=n%10;
    unsigned d2=(n/10)%10;
    unsigned d3=n/100;

    unsigned sum=d1+d2+d3;
    printf("Sum of digits: %u\n",sum);
}

//c)
void task1_c(unsigned n){
    unsigned d1=n%10;
    unsigned d2=(n/10)%10;
    unsigned d3=n/100;

    unsigned reversed = d1*100+d2*10+d3;
    printf("Reversed number: %u\n", reversed);
}

void task1(){
    unsigned n;
    printf("Enter a three-digit number:");
    scanf("%u",&n);

    task1_a(n);
    task1_b(n);
    task1_c(n);
}

// Task 2
void task2(){
    int n;
    printf("Enter a three-digit number: ");
    scanf("%d", &n);

    int a=n/100;
    int b=(n/10)%10;
    int c=n%10;

    if(a!=b && a!=c && b!=c){
        printf("%d%d%d\n", a, b, c);
        printf("%d%d%d\n", a, c, b);
        printf("%d%d%d\n", b, a, c);
        printf("%d%d%d\n", b, c, a);
        printf("%d%d%d\n", c, a, b);
        printf("%d%d%d\n", c, b, a);
    }
}

// Task 3
//a)
void task3_a(){
    int a,b,c;
    
    printf("Task 3a\n");
    printf("Enter three numbers:");
    scanf("%d,%d,%d",&a,&b,&c);
    
    int product=a*b*c;
    
    printf("Product = %d\n", product);
}

//b) 
void task3_b(){ 
    long long a,b,c;
    
    printf("Task 3b\n");
    printf("Enter a,b,c:");
    scanf("%lld,%lld,%lld",&a,&b,&c);
    
    long long product=a*b*c;
    
    printf("Product = %lld\n", product);
}

// Task 4
void task4(){
    unsigned char a,b;
    
    printf("Enter two numbers:");
    scanf("%hhu %hhu",&a,&b);
    
    unsigned short product=a*b;
    
    printf("Product = %hu\n",product);
}

// Task 5
void task5(){
    long a, b;

    printf("Enter two long integers: ");
    int k = scanf("%ld %ld", &a, &b);

    if(k != 2){
        printf("Invalid input. Please enter two long integers.\n");
        return;
    }

    printf("You entered: %ld, %ld\n", a, b);

    if(a > b){
        printf("Bigger: %ld\n", a);
        printf("Smaller: %ld\n", b);
    } else if(b > a){
        printf("Bigger: %ld\n", b);
        printf("Smaller: %ld\n", a);
    } else {
        printf("Both numbers are equal: %ld\n", a);
    }
}

// Task 6
int max_abs(int x, int y){
    if(abs(x) > abs(y)) return x;
    return y;
}

void task6(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max_num = max_abs(a, b);
    max_num = max_abs(max_num, c);
    printf("%d", max_num);
}

// Task 7
void task7() {
    double a,b,c;

    printf("Enter a,b,c:");
    scanf("%lf %lf %lf",&a,&b,&c);

    if (a==0) {
        printf("Not a quadratic equation");

        if (b==0) {
            if (c==0) {
                printf("Infinite solutions");
            }
            else {
                printf("No solution");
            }
        }
        else {
            double x=-c/b;
            printf("One root\n");
            printf("x = %lf",x);
        }

        return;
    }

    double D=b*b-4*a*c;

    if (D>0) {
        double x1=(-b+sqrt(D))/(2*a);
        double x2=(-b-sqrt(D))/(2*a);

        printf("Two roots\n");
        printf("x1=%lf,x2=%lf",x1,x2);
    }
    else if (D==0) {
        double x=-b/(2*a);

        printf("One root\n");
        printf("x=%lf",x);
    }
    else {
        printf("No real roots");
    }
}
int main() {
    task1();
    task2();
    task3_a();
    task3_b();
    task4();
    task5();
    task6();
    task7();

    return 0;
}