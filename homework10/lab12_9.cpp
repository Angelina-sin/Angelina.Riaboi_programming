#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream f("C:\\Users\\Asus\\Desktop\\homework10\\input9.txt");

    if(!f){
        cout<<"File not opened\n";
        return -1;
    }

    vector<unsigned long long>a;
    unsigned long long x;

    while(f>>x){
        a.push_back(x);
    }

    f.close();

    if(a.size()<2){
        cout<<"Not enough numbers\n";
        return 0;
    }

    for(size_t i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            a[i]=a[i]*a[i];
        }
    }

    ofstream g("C:\\Users\\Asus\\Desktop\\homework10\\output9.txt");

    for(size_t i=0;i<a.size();i++){
        g<<a[i]<<" ";
    }

    g.close();

    return 0;
}