#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int ans =0;
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    unordered_map<int, int> key;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        key[b[i]] = i+1;
    }
    for(int i=0; i<n; i++){
        c[i] = key[a[i]];
    }
    int greatest=0;
    for(int i=0; i<n; i++){
        if(c[i]>greatest) greatest=c[i];
        else ans++;
    }
    cout << ans;
}