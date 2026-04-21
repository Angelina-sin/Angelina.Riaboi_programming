#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    unsigned n;
    cout << "n = ";
    cin >> n;

    for(unsigned i=1; i<=n; i++){
        cout.width(7);
        cout << i;
    }
    cout << endl;

    for(unsigned i=1; i<=n; i++){
        cout.width(7);

        double r = sqrt(i);

        if (r == (int)r)
            cout << fixed << setprecision(0) << r;
        else
            cout << fixed << setprecision(2) << r;
    }

    return 0;
}