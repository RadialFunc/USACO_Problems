#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n], t[n], a[n+2];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }   
    for(int i=0; i<n; i++) cin >> t[i];
    for(int i=0; i<n; i++){
        a[i+1] = p[i]-t[i];
    }
    a[0] = 0; a[n+1] = 0;
    int ans=0;
    for(int i=0; i<=n; i++){
        ans+= abs(a[i] - a[i+1]);
    }
    cout << ans/2;
}