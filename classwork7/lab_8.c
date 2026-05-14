#include<stdio.h>
#define N 25

void print_matrix(double matrix[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Task1
void task1(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n, m;
    printf("Input n and m: ");
    scanf("%d %d", &n, &m);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j] == m){
                matrix[i][j] = n;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Task2 (home)
void task2(){
    double matrix[3][3]={{1.0,2,3},{4,5,6},{7,8,9}};
    int i,j;
    double a;

    printf("Input i j and a: ");
    scanf("%d %d %lf",&i,&j,&a);

    if(i>=0 && i<3 && j>=0 && j<3){
        matrix[i][j]=a;
    }else{
        printf("Wrong indexes\n");
    }

    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            printf("%.2lf ",matrix[r][c]);
        }
        printf("\n");
    }
}

//Task3 
int input_matrix(double matr[N][N], int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("a[%d][%d]: ", i, j);
            int r=scanf("%lf", &matr[i][j]);
            if (r!=1) return -1;    
        }
    }
    return 0;
}
void task3(){
    double matrix[N][N];
    int n, m;
    printf("Input n and m: ");
    scanf("%d %d", &n, &m);
    input_matrix(matrix, n, m);
    print_matrix(matrix, n, m);
}

//Task4 (home)
void input_matrix_rows(double matr[N][N], int n, int m){
    for(int i=0;i<n;i++){
        printf("Row %d: ",i);
        for(int j=0;j<m;j++){
            scanf("%lf",&matr[i][j]);
        }
    }
}

void task4(){
    double matrix[N][N];
    int n,m;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    input_matrix_rows(matrix,n,m);
    print_matrix(matrix,n,m);
}

//Task5
void transpose(double matr[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            double c=matr[i][j];
            matr[i][j]=matr[j][i];
            matr[j][i]=c;
        }
    }    
}

void task5(){
    double a[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_matrix(a, n, n);
    transpose(a, n);
    print_matrix(a, n, n);
}
//Task5 variant 2
void transpose2(double matr[N][N], double matrout[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrout[j][i]=matr[i][j];
        }
    }    
}

void task5_2(){
    double matr[N][N];
    double matr_out[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_matrix(matr, n, n);
    transpose2(matr, matr_out, n);
    print_matrix(matr_out, n, n);
}

//Task6 (home)
void task6(){
    double A[100][100];
    int n,m,k;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    printf("Input k: ");
    scanf("%d",&k);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&A[i][j]);
        }
    }
    double sum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-j==k){
                sum+=A[i][j];
            }
        }
    }
    printf("Sum = %.2lf\n",sum);
}

//Task7 (home)
double determinant(double a[N][N], int n){
    double det=1;

    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            return 0;
        }
        for(int j=i+1;j<n;j++){
            double factor=a[j][i]/a[i][i];

            for(int k=i;k<n;k++){
                a[j][k]=a[j][k]-factor*a[i][k];
            }
        }
        det=det*a[i][i];
    }
    return det;
}

void task7(){
    double a[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Input matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    double det=determinant(a,n);
    printf("Determinant = %.2lf\n",det);
}

int main(){
    task1();
    task2();
    task3();
    task4();
    task5();
    task5_2();
    task6();
    task7();
    return 0;
}