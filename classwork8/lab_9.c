#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>

//Task1
size_t input(double* r, size_t n){
    for(size_t i=0; i<n; i++){
        printf("r[%zu]= ", i);
        int a=scanf("%lf", &r[i]);
        if (a!=1) return i;
    }
    return n;
}
double sum_sqr(double* r, size_t n){
    double s=0;
    for(size_t i=0; i<n; i++){
        s+=r[i]*r[i];
    }
    return s;
}

void task_1(){
    size_t n;
    printf("Input n: ");
    scanf("%zu", &n);
    double* r = (double*)malloc(n*sizeof(double));
    size_t k = input(r, n);
    double sum = sum_sqr(r, k);
    printf("sum= %lf\n", sum);
    free(r);
}

//Task2
bool is_sqr(int n){
    int m=(int)floor(sqrt(n));
    return m*m==n;
}

bool is_cube(int n){
    int m=(int)round(pow(n,1.0/3.0));
    return m*m*m==n;
}
int input_int(int* r, int n){
    for(int i=0; i<n; i++){
        printf("r[%d]= ", i);
        int a=scanf("%d", &r[i]);
        if (a!=1) return i;
    }
    return n;
}


void task_2(){
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    int* r=(int*)malloc(n*sizeof(int));
    int k = input_int(r, n);
    int y=0,w=0;
    for(int i=0; i<k; i++){
        if (is_sqr(r[i])){
            y++;
        }
        if (is_cube(r[i])){
             w++; 
        }
    }
    printf("sqr= %d\n", y);
    printf("cube= %d\n", w);
    free(r);
}

//Task3
double* input_r(int n){
    double* h=(double*) calloc(n, sizeof(double));
    for(int i=0; i<n; i++){
        scanf("%lf", &h[i]);
    }
    return h;
}

int diff(const double* v1, const double* v2, double* v3, int n){
    for(int i=0; i<n; i++){
        v3[i]=v1[i]-v2[i];
    }
    return 0;
}

void task_3(){
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    double* v1=input_r(n);
    double* v2=input_r(n);
    double* v3=calloc(n, sizeof*v3);
    diff(v1, v2, v3, n);
    for(int i=0; i<n; i++){
        printf("%lf ", v3[i]);
    }
    printf("\n");
    free(v1);
    free(v2);   
    free(v3);
}

//Task4
void task_4(){
    int n;
    printf("Input n (size of nxn matrix): ");
    scanf("%d", &n);
    double* mat1=(double*) malloc(n*n*sizeof(double));
    double* mat2=(double*) malloc(n*n*sizeof(double));

    printf("Input first matrix (%dx%d):\n", n, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &mat1[i*n+j]);
        }
    }

    printf("Input second matrix (%dx%d):\n", n, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &mat2[i*n+j]);
        }
    }
    double* mat3=(double*) calloc(n*n, sizeof *mat3);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat3[i*n+j]=mat1[i*n+j]+mat2[i*n+j];
        }
    }

    printf("Resulting matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.2lf ", mat3[i*n+j]);
        }
        printf("\n");
    }
    free(mat1);
    free(mat2);
    free(mat3);
}

int main(){
    task_1();
    task_2();
    task_3();
    task_4();
    return 0;
}