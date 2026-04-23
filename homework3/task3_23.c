#include <stdio.h>

// Task 3.23 d)

double sReLu(double tl, double tr, double al, double ar, double x){
    if(x<=tl){
        return tl+al*(x-tl);
    }   
    else if (x<tr){
        return 0;
    }
    else{ // x>=tr
        return tr+ar*(x-tr);
    }
}

void task3_23(){

    double tl, tr, al, ar, x;
    printf("Enter tl, tr, al, ar, x:");
    scanf("%lf %lf %lf %lf %lf", &tl, &tr, &al, &ar, &x);

    double y = sReLu(tl, tr, al, ar, x);

    printf("sReLu(%lf) = %lf\n", x, y);

}

int main(){
    task3_23();

    return 0;
}