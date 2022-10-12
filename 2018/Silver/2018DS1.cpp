#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n,m,c; cin >> n>>m>>c;
    int locs[n];
    for(int i=0; i<n; i++) cin >> locs[i];
    sort(locs, locs+n);
    int l=0; int h = 1e9;
    int ans=0;
    while(l!=h){
        int d = l+(h-l)/2;
        int counter = 0;
        ll end=0;
        int lastfilled=0;
        int highest=0;
        for(int i=0; i<n; i++){
            if(locs[i]<=end && i-lastfilled <= c-1){}
            else{
                counter++;
                end = d + locs[i];
                lastfilled = i;
            }
        }
        if(counter<=m){
            if(h!=d){
            ans = d;
            h = d;}
            else break;
        }else{
            if(l!=d) l = d;
            else break;
        }
    }
    cout << ans;
}