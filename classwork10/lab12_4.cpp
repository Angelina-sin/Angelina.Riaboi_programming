#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;

    int* m = new int[n];

    for(int i=0; i<n; i++){
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }

    double* x = new double[n];

    ifstream f("C:\\Users\\Asus\\Desktop\\classwork10\\input4.txt");

    if(!f){
        cout << "File is not opened\n";
        return -1;
    }

    int i = 0;
    while(i < n && f >> x[i]){
        i++;
    }

    if(i < n){
        cout << "Not enough data in file!\n";
        return -1;
    }

    f.close();

    ofstream g("C:\\Users\\Asus\\Desktop\\classwork10\\output4.txt");

    if(!g){
        cout << "Output file error\n";
        return -1;
    }

    for(int i=0; i<n; i++){
        double z = pow(x[i], m[i]);
        g << z << endl;
    }

    g.close();

    delete[] m;
    delete[] x;

    return 0;
}