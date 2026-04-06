#include "Ratio.h"
#include <stdio.h>

int main(){
    Rational x, y;

    printf("Enter x: ");
    input_Rational(&x);

    printf("Enter y: ");
    input_Rational(&y);

    printf("x = ");
    print_Rational(x);

    printf("\ny = ");
    print_Rational(y);

    printf("\nsum = ");
    print_Rational(add(x, y));

    printf("\nmul = ");
    print_Rational(mul(x, y));

    return 0;
}