#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;

    char str[11];
    unsigned long long x, sum = 0;

    cout << "Input numbers:\n";

    for(int i=0; i<n;){
        cin>>str;

        if(strlen(str)!=10){
            cout << "Error\n";
            continue;
        }

        bool ok=true;
        for(int j=0; j<10; j++){
            if(str[j] < '0' || str[j] > '9'){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << "Error\n";
            continue;
        }

        x = atoll(str);
        sum += x;
        cout<<str<<" -> "<<x<<", sum = "<<sum<<endl;
        i++;
    }
    
    cout << "Final sum = " << sum << endl;
    return 0;
}