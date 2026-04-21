#include <iostream>
#include <string>

using namespace std;

int count_word(string s, string w){
    int cnt=0;
    size_t pos=0;

    while((pos=s.find(w, pos))!=string::npos){
        cnt++;
        pos += w.length();
    }

    return cnt;
}

int main(){
    string s, word, sub;

    cout<<"Enter string: ";
    getline(cin, s);

    cout<<"Enter word: ";
    cin >> word;

    cout<<"Enter substring: ";
    cin>>sub;

    cout<<"Word count = "<<count_word(s, word)<<endl;
    cout<<"Substring count = "<<count_word(s, sub)<<endl;

    return 0;
}