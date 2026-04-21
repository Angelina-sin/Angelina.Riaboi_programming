#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ifstream f("C:\\Users\\Asus\\Desktop\\classwork10\\input5.txt");

    if(!f){
        cout << "File not opened\n";
        return -1;
    }

    vector<unsigned long long> A;
    unsigned long long x;

    while(f >> x){
        A.push_back(x);
    }

    f.close();

    for(int i=A.size()-1; i>=0; i--){
        cout << fixed << setprecision(3) << sqrt(A[i]) << endl;
    }

    return 0;
}