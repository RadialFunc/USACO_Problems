#include <iostream>
using namespace std;

int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n,k;
    cin >> n >>k;
    int l=0;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        if (l+word.length() > k){
            l=word.length();
            cout << endl<< word;
        } else{
            if(l==0){
                cout << word;
            }else{
            cout <<" "<< word ;}
            l += word.length();
        }
    }
}