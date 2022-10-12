#include <bits/stdc++.h>
#include <unordered_map>
using ll = long long;
using namespace std;

set<ll> pastures;
unordered_map<ll, bool> starting;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n,m; cin >>n>>m;
    for(int i=0; i<m; i++){
        ll s, e; cin >> s>>e;
        pastures.insert(s); pastures.insert(e);
        starting[s]=true; starting[e]=false;
    }
    ll l=0; ll h = 1e18;
    ll end = *pastures.rbegin();
    int ans=0;
    while(l!=h){
        ll d = (l+h)/2;
        int last = *pastures.begin();
        bool check = true;
        for(int i=1; i<n; i++){
            if(last + d > end){check=false; break;}
            else{
                int find = *pastures.lower_bound(last+d);
                if(starting[find]) last = find;
                else last+=d;
            }
        }
        if(check){
            if(l!=d){
                l=d; ans=d;
            }else break;
        }else{
            if(h!=d) h=d;
            else break;
        }
    }
    cout << ans;
}