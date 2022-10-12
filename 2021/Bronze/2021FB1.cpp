#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> convert;
    convert["Ox"]=0;
    convert["Tiger"]=1;
    convert["Rabbit"]=2;
    convert["Dragon"]=3;
    convert["Snake"]=4;
    convert["Horse"]=5;
    convert["Goat"]=6;
    convert["Monkey"]=7;
    convert["Rooster"]=8;
    convert["Dog"]=9;
    convert["Pig"]=10;
    convert["Rat"]=11;
    map<string, int> born;
    born["Bessie"]=0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string a1, a2, a3, a4, a5, a6, a7, a8;
        cin >> a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8;
        int cow = born[a8];

        if(a4=="previous"){
            int i=1; 
            while ((((cow-i) % 12 + 12) % 12) != convert[a5]) i++;
            born[a1] = cow-i;
        }
        if(a4=="next"){
            int i=1; 
            while ((((cow+i) % 12 + 12) % 12) != convert[a5]) i++;
            born[a1] = cow+i;
        }
    }
    cout << abs(born["Elsie"]);
}