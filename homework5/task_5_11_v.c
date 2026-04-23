// task 5.11.v

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter the number of terms n:");
    scanf("%d",&n);

    if(n<=0){
        printf("Number of terms must be positive.\n");
        return 0;
    }

    double a1=1,a2=1,ak;
    double sum=0;
    double factorial;

    for(int k=1;k<=n;k++){
        if(k==1)ak=a1;
        else if(k==2)ak=a2;
        else{
            ak=a2+a2/pow(2.0,k);
            a1=a2;
            a2=ak;
        }

        factorial=1;
        for(int i=1;i<=k;i++)factorial*=i;

        sum+=factorial/ak;
    }

    printf("Sum S_%d=%.6lf\n",n,sum);

    return 0;
}