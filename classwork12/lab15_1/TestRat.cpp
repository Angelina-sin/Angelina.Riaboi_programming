#include <iostream>
#include <math.h>
#include "Rat.h"

using namespace std;

int main() {

    Rational b(1,2);
    Rational c;

    cin>>c;
    Rational q=b+c;
    cout<<"b+c="<<q<<endl;

    int n;
    cin>>n;

    if(n<=0) return 0;

    Rational* mass = new Rational[n];

    for (int i=0; i<n; i++) {
        cin >> mass[i];
    }

    q=mass[0];

    for (int i=1; i<n; i++) {
        if (mass[i].less(q)) {
            q=mass[i];
        }
    }

    cout<<"min= " <<q<<endl;

    q.save("rat.txt");

    delete[] mass;

    Rational eps(1,100);
    Rational s(0,1);
    Rational t(1,1);

    int k=1;

    double sumCheck = 0.0;

    while (!t.less(eps)) {

        if (k%2==0) {
            s=s+Rational(-1,1).mul(t);
        }
        else {
            s=s+t;
        }

        sumCheck += pow(-1, k+1)*(1.0/(k*k)); 

        k++;
        t = Rational(1, k*k);
    }

    cout<<"s= "<<s<<endl;

    double pi_ref = (M_PI*M_PI)/12.0;

    cout<<"Series approx= "<<sumCheck<<endl;
    cout<<"pi^2/12= "<<pi_ref<<endl;

    cout<<"error= "<< fabs(sumCheck-pi_ref)<<endl;

    return 0;
}