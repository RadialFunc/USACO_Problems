#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int l,n,f,b;
    cin >> l>>n>>f>>b;
    pair<int, int> stops[n];
    for(int i=0; i<n; i++){
        int x,y; cin >>x>>y;
        stops[i] = make_pair(x,y);
    }
    int highest =0;
    set<int> goodstops;
    for(int i=n-1; i>=0; i--){
        if(stops[i].second > highest){
            highest =stops[i].second;
            goodstops.insert(i);
        }
    }
    int past =0;
    ll ans = 0;
    for(auto elem: goodstops){
        ans += (long long)(stops[elem].first - past) * (f-b) * stops[elem].second;
        past = stops[elem].first;
    }
    cout << ans;
}
