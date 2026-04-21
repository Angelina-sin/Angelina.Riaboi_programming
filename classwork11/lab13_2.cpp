#include <iostream>
#include <string>

using namespace std;

string mood_str(string s){
    int first = s.find(',');
    int last = s.rfind(',');

    if(first == string::npos){
        while(!s.empty() && s[0]==' ') s.erase(0,1);
        return s;
    }

    if(first == last){
        return s.substr(last);
    }

    return s.substr(first+1, last-first-1);
}

int main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << mood_str(s);
    return 0;
}