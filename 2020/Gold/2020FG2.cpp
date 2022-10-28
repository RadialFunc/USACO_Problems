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
    int pairs[n][2];
    for(int i=0; i<n; i++){
        cin >> pairs[i][0]>>pairs[i][1];
        count[pairs[i][0]]++; count[pairs[i][1]]--;
    }
    for(int i=1; i<=2*n; i++) count[i] += count[i-1];
    ll ans = 0;
    for(int i=0; i<n; i++) ans = (ans+powersoftwo[n-1-count[pairs[i][0]-1]])%MOD;
    cout << ans;
}