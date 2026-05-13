#ifndef __RAT_H_
#define __RAT_H_

#include <iostream>
#include <fstream>
using namespace std;

class Rational{
    int num;
    int den; 

private:
    int gcd(int a, int b);
    void reduce();

public:
    Rational(int x, int y){
        if(y==0) y=1;
        num=x;
        den=y;
        reduce();
    }

    Rational(){
        num=0;
        den=1;
    }

    void input();
    void output();

    Rational add(Rational z);
    Rational mul(Rational z);
    bool less(Rational z);

    void save(const char* f){
        ofstream g(f);
        if(!g){
            cout<<"can't open file "<<f;
            return;
        }
        g<<num<<"/"<<den<<"\n";
    }

    friend istream& operator>>(istream& in, Rational& r){
        cout<<"input num, den:";
        in>>r.num>>r.den;
        if(r.den==0) r.den=1;
        r.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, Rational r){
        out<<r.num<<"/"<<r.den;
        return out;
    }

    Rational operator+(Rational z){
        return add(z);
    }
};

#endif