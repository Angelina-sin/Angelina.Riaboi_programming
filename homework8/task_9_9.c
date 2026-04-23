//task 9.9 t
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M;
    printf("Enter N and M: ");
    scanf("%d %d", &N, &M);

    int** mat=(int**)malloc(N*sizeof(int*));
    for(int i=0; i<N; i++){
        mat[i]=(int*)malloc(M*sizeof(int));
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");

        if((i+1)%2==0){
            for(int j=0; j<M; j++){
                printf("0 "); 
            }
            printf("\n");
        }
    }

    for(int i=0; i<N; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}