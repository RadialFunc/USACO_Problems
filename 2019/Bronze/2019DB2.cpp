#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);   
    int n;
    cin >> n;
    string chars;
    cin >> chars;
    for(int k=1; k<n; k++){
        bool poss=true;
        vector<string> subs;
        for(int i=0; i< n-k+1; i++){
            subs.push_back(chars.substr(i, k));
        }
        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<n-k+1; j++){
                if (subs[i]==subs[j] && i !=j){
                    poss=false;
                }
            }
        }
        if (poss==true){
            cout << k;
            k=n;
        }
    }
}