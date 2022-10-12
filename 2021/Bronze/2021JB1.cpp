#include <iostream>
using namespace std;

int index(string alph, char a){
    for(int i=0; i<26; i++){
        if(alph[i] == a) return i;
    }
}

int main(){
    string alph, sung;
    cin >> alph;
    cin >> sung;
    int total=1;
    for(int i=1; i<sung.size(); i++){
        if(index(alph, sung[i]) <= index(alph, sung[i-1])) total++;
    }
    cout << total;
}