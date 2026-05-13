#include <iostream>
#include <cmath>
using namespace std;

class Vector3{
    double v[3];

public:
    Vector3(){
        for(int i=0;i<3;i++)v[i]=0;
    }

    Vector3(double x,double y,double z){
        v[0]=x;
        v[1]=y;
        v[2]=z;
    }

    double& operator[](int i){
        return v[i];
    }

    const double& operator[](int i)const{
        return v[i];
    }

    Vector3 operator+(const Vector3& b)const{
        return Vector3(v[0]+b[0],v[1]+b[1],v[2]+b[2]);
    }

    Vector3 operator-(const Vector3& b)const{
        return Vector3(v[0]-b[0],v[1]-b[1],v[2]-b[2]);
    }

    Vector3 operator*(double k)const{
        return Vector3(v[0]*k,v[1]*k,v[2]*k);
    }

    double operator*(const Vector3& b)const{
        return v[0]*b[0]+v[1]*b[1]+v[2]*b[2];
    }

    double abs()const{
        return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    }

    friend istream& operator>>(istream& in,Vector3& a){
        cout<<"Input vector (x y z): ";
        in>>a.v[0]>>a.v[1]>>a.v[2];
        return in;
    }

    friend ostream& operator<<(ostream& out,const Vector3& a){
        out<<"("<<a.v[0]<<", "<<a.v[1]<<", "<<a.v[2]<<")";
        return out;
    }
};

class Matrix3{
    double m[3][3];

public:
    Matrix3(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                m[i][j]=0;
    }

    double* operator[](int i){
        return m[i];
    }

    const double* operator[](int i)const{
        return m[i];
    }

    Matrix3 operator+(const Matrix3& b)const{
        Matrix3 r;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                r[i][j]=m[i][j]+b[i][j];
        return r;
    }

    Matrix3 operator-(const Matrix3& b)const{
        Matrix3 r;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                r[i][j]=m[i][j]-b[i][j];
        return r;
    }

    Matrix3 operator*(const Matrix3& b)const{
        Matrix3 r;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                r[i][j]=0;
                for(int k=0;k<3;k++){
                    r[i][j]+=m[i][k]*b[k][j];
                }
            }
        }
        return r;
    }

    Vector3 operator*(const Vector3& v)const{
        Vector3 r;
        for(int i=0;i<3;i++){
            r[i]=0;
            for(int j=0;j<3;j++){
                r[i]+=m[i][j]*v[j];
            }
        }
        return r;
    }

    double abs()const{
        double s=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                s+=m[i][j]*m[i][j];
        return sqrt(s);
    }

    double det()const{
        return
            m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])-
            m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0])+
            m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
    }

    friend istream& operator>>(istream& in,Matrix3& a){
        cout<<"Input matrix 3x3:\n";
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                in>>a.m[i][j];
        return in;
    }

    friend ostream& operator<<(ostream& out,const Matrix3& a){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                out<<a.m[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }
};

int main(){
    Vector3 v1,v2;
    Matrix3 A,B;

    cin>>v1;
    cin>>v2;

    cout<<"v1 = "<<v1<<endl;
    cout<<"v2 = "<<v2<<endl;

    cout<<"v1 + v2 = "<<v1+v2<<endl;
    cout<<"Scalar product = "<<(v1*v2)<<endl;
    cout<<"|v1| = "<<v1.abs()<<endl;

    cin>>A;
    cin>>B;

    cout<<"A:\n"<<A;
    cout<<"B:\n"<<B;

    cout<<"A + B:\n"<<A+B;

    cout<<"A * v1 = "<<A*v1<<endl;

    cout<<"|A| = "<<A.abs()<<endl;

    cout<<"det(A) = "<<A.det()<<endl;

    return 0;
}