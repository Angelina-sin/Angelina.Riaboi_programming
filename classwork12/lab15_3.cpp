#include <iostream>
#include <fstream>
using namespace std;

class Polynome {
    double* c;
    int n;

public:
    Polynome():c(nullptr), n(0) {}

    Polynome(int n) {
        this->n=n;
        c=new double[n]();
    }

    Polynome(int n, double* d) {
        this->n=n;
        c=new double[n];
        for (int i=0; i<n; i++)
            c[i]=d[i];
    }

    Polynome(const Polynome& p) {
        this->n = p.n;
        this->c = new double[n];
        for (int i=0; i<n; i++)
            c[i]=p.c[i];
    }

    ~Polynome() {
        delete[] c;
    }

    int size() const {
        return n;
    }

    double& operator[](int k) {
        return c[k];
    }

    const double& operator[](int k) const {
        return c[k];
    }

    void show() const {
        if (n==0) {
            cout<<"0\n";
            return;
        }

        cout << c[0];
        for (int i=1; i<n; i++)
            cout<<"+"<<c[i]<<"*x^"<<i;
        cout<<"\n";
    }

    friend istream& operator>>(istream& in, Polynome& p) {
        cout<<"input degree: ";
        in>>p.n;

        delete[] p.c;
        p.c=new double[p.n];

        cout<<"input coefficients:\n";
        for (int i=0; i<p.n; i++)
            in>>p.c[i];

        return in;
    }

    friend ostream& operator<<(ostream& out, const Polynome& p) {
        if (p.n==0) return out<<"0";

        out<<p.c[0];
        for (int i=1; i<p.n; i++)
            out<<"+"<<p.c[i]<<"*x^"<<i;

        return out;
    }

    void writeBinary(const char* file) {
        ofstream f(file, ios::binary);
        f.write((char*)&n, sizeof(n));
        f.write((char*)c, sizeof(double)*n);
        f.close();
    }

    void readBinary(const char* file) {
        ifstream f(file, ios::binary);

        delete[] c;

        f.read((char*)&n, sizeof(n));
        c = new double[n];

        f.read((char*)c, sizeof(double) * n);
        f.close();
    }
};

int main() {

    Polynome p;

    cin>>p;

    cout<<"polynomial: "<<p<<endl;

    if (p.size()>1) {
        p[1]=5;
    }

    cout<<"After change: "<<p<<endl;

    Polynome p2=p;
    cout<<"copy: "<<p2<<endl;

    p.writeBinary("poly.bin");

    Polynome p3;
    p3.readBinary("poly.bin");

    cout<<"From file: "<<p3<<endl;

    return 0;
}