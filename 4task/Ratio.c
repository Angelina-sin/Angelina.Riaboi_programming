#include <stdio.h>
#include <stdlib.h>
#include "Ratio.h"

int nsd(int x, int y){
    if(y==0) return x;
    return nsd(y, x % y);
}

void reduce(Rational *r){
    int a = nsd(abs(r->numerator), r->denominator);
    r->numerator /= a;
    r->denominator /= a;
}

void print_Rational(Rational r){
    printf("%d/%u", r.numerator, r.denominator);
}

int input_Rational(Rational *r){
    return scanf("%d/%u", &r->numerator, &r->denominator) == 2;
}

Rational add(Rational x, Rational y){
    Rational z;
    z.numerator = x.numerator*y.denominator+y.numerator*x.denominator;
    z.denominator = x.denominator*y.denominator;
    reduce(&z);
    return z;
}

Rational mul(Rational x, Rational y){
    Rational z;
    z.numerator = x.numerator*y.numerator;
    z.denominator = x.denominator*y.denominator;
    reduce(&z);
    return z;
}