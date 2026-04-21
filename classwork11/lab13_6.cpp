#include <iostream>
#include <sstream>

using namespace std;

string shortest_word(string s){
    stringstream u(s);
    string word, shortest;

    u >> shortest;

    while(u >> word){
        if(word.size() < shortest.size()){
            shortest = word;
        }
    }

    return shortest;
}

int main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << shortest_word(s);
    return 0;
}