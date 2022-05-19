#include <iostream>
using namespace std;

int main(){
    int ans =0;
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=1; i<=n; i++){
        int change = b[i-1];
        for(int j=0; j<n; j++){
            if(a[j] == change) c[j] = i;
        }
    }
    int greatest=0;
    for(int i=0; i<n; i++){
        if(c[i]>greatest) greatest=c[i];
        else ans++;
    }
    cout << ans;
}