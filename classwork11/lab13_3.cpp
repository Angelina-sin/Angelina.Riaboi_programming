#include <iostream>
#include <sstream>

using namespace std;

string remove_Last(string s){
    stringstream u(s);
    string word, result="";

    while(u >> word){
        if(word.size() > 0)
            word.pop_back();
        result += word + " ";
    }

    return result;
}

int main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << remove_Last(s);
    return 0;
}