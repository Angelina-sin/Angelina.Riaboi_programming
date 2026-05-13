#include<stdio.h>
#include<math.h>
#define N 100

void print_matrix(double matrix[N][N], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.2lf ",matrix[i][j]);
        }
        printf("\n");
    }
}

//Task1
void task1(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n,m;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j]==m){
                matrix[i][j]=n;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

//Task2
void task2(){
    double matrix[3][3]={{1.0,2,3},{4,5,6},{7,8,9}};
    int i,j;
    double a;

    printf("Input i j and a: ");
    scanf("%d %d %lf",&i,&j,&a);

    if(i>=0&&i<3&&j>=0&&j<3){
        matrix[i][j]=a;
    }

    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            printf("%.2lf ",matrix[r][c]);
        }
        printf("\n");
    }
}

//Task3
int input_matrix(double a[N][N],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    return 0;
}

void task3(){
    double a[N][N];
    int n,m;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    input_matrix(a,n,m);
    print_matrix(a,n,m);
}

//Task4
void input_rows(double a[N][N],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&a[i][j]);
        }
    }
}

void task4(){
    double a[N][N];
    int n,m;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    input_rows(a,n,m);
    print_matrix(a,n,m);
}

//Task5
void transpose(double a[N][N],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            double t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
}

void task5(){
    double a[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    input_matrix(a,n,n);
    transpose(a,n);
    print_matrix(a,n,n);
}

//Task5_2
void transpose2(double a[N][N],double b[N][N],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[j][i]=a[i][j];
        }
    }
}

void task5_2(){
    double a[N][N],b[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    input_matrix(a,n,n);
    transpose2(a,b,n);
    print_matrix(b,n,n);
}

//Task6
void task6(){
    double a[N][N];
    int n,m,k;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    printf("Input k: ");
    scanf("%d",&k);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&a[i][j]);
        }
    }

    double sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-j==k){
                sum+=a[i][j];
            }
        }
    }

    printf("Sum = %.2lf\n",sum);
}

//Task7
double determinant(double a[N][N],int n){
    double det=1;

    for(int i=0;i<n;i++){
        int max=i;

        for(int k=i+1;k<n;k++){
            if(fabs(a[k][i])>fabs(a[max][i]))
                max=k;
        }

        if(a[max][i]==0) return 0;

        if(max!=i){
            for(int j=0;j<n;j++){
                double t=a[i][j];
                a[i][j]=a[max][j];
                a[max][j]=t;
            }
            det=-det;
        }

        for(int j=i+1;j<n;j++){
            double f=a[j][i]/a[i][i];
            for(int k=i;k<n;k++){
                a[j][k]-=f*a[i][k];
            }
        }

        det*=a[i][i];
    }

    return det;
}

void task7(){
    double a[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }

    printf("Determinant = %.2lf\n",determinant(a,n));
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
