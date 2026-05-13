#include <iostream>
#include "Rat.h"

void Rational::input(){
    cout<<"input num, den:";
    cin>>num>>den;
    if(den==0) den=1;
    reduce();
}

void Rational::output(){
    cout<<num<<"/"<<den<<"\n";
}

int Rational::gcd(int a, int b){
    a=abs(a);
    b=abs(b);
    while(a != 0){
        int c=a;
        a=b%a;
        b=c;
    }
    return b;
}

void Rational::reduce(){
    int a = gcd(num, den);
    num /=a;
    den /= a;
    if(den<0){
        den = -den;
        num = -num;
    }
}

Rational Rational::add(Rational z){
    Rational n;
    n.num =num*z.den+z.num*den;
    n.den =den*z.den;
    n.reduce();
    return n;
}

Rational Rational::mul(Rational z){
    Rational n;
    n.num = num*z.num;
    n.den = den*z.den;
    n.reduce();
    return n;
}

bool Rational::less(Rational z){
    return num*z.den<z.num*den;
}