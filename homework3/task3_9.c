#include <stdio.h>

void task3_9a(){
    int x,y,z;

    printf("Enter x,y,z (a):");
    scanf("%d %d %d",&x,&y,&z);

    int sum=x+y+z;
    int expr=x*y-x*z+y*z;
    int prod = x*y*z;

    int max_a=sum;
    if(expr>max_a) max_a=expr;
    if(prod>max_a) max_a=prod;

    printf("Task 9a max: %d\n",max_a);
}

void task3_9b(){
    int x,y,z;

    printf("Enter x,y,z (b):");
    scanf("%d %d %d",&x,&y,&z);

    int xy=x*y;
    int xz=x*z;
    int yz=y*z;

    int max_b=xy;
    if(xz>max_b) max_b=xz;
    if(yz>max_b) max_b=yz;

    printf("Task 9b max: %d\n",max_b);
}

int main(){
    task3_9a();
    task3_9b();

    return 0;
}