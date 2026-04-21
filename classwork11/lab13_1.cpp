#include <iostream>
#include <string>

using namespace std;

string return_string(string s){
    int k = s.find(':');
    if(k == string::npos) return s;

    int i = s.find(',', k);
    if(i == string::npos) return s.substr(k+1);

    return s.substr(k+1, i-k-1);
}

int main(){
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "The substring is: " << return_string(s) << endl;
    return 0;
}