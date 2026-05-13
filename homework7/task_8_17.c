#include <stdio.h>
#define N 25

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int size=2*n+1;

    if(size>N){
        printf("Error: size too large\n");
        return 0;
    }

    int a[N][N],b[N][N];

    printf("Enter matrix %dx%d:\n",size,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            b[j][size-1-i]=a[i][j];
        }
    }

    printf("Rotated matrix:\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
