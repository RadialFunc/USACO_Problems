#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    int wait[n]; 
    for(int i=0; i<n; i++) cin >> wait[i];
    sort(wait, wait+n, greater<int>());
    int ans=0;
    for(int i=0; i<n; i++){
        if(wait[i] >= i) ans++;
        else break;
    }
    cout << ans;
}