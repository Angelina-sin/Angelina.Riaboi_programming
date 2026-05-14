#include <stdio.h>
#define N 25

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int size=2*n+1;
    int matrix[N][N];
    int rotated[N][N];

    printf("Input matrix %dx%d:\n", size, size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            rotated[j][size-1-i]=matrix[i][j];
        }
    }
    printf("Rotated matrix:\n");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", rotated[i][j]);
        }
        printf("\n");
    }
    return 0;
}