#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD = 1000000007;

int main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n; cin >>n;
    ll powersoftwo[n]; powersoftwo[0]=1;
    for(int i=1; i<n; i++) powersoftwo[i] = (powersoftwo[i-1]*2)%MOD;
    map<int, int> count;
    for(int i=0; i<n; i++){
        int a,b; cin >>a>>b;
        count[a]++; count[b]--;
    }
    for(int i=2; i<=2*n; i++) count[i] += count[i-1];
    ll ans = 0;
    for(int i=1; i<=2*n; i++) ans = (ans+powersoftwo[n-1-count[i]])%MOD;
    cout << ans;
}