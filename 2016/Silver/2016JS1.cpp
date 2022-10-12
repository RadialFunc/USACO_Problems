#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n,k; cin >> n>>k;
    int locs[n];
    for(int i=0; i<n; i++) cin >> locs[i];
    sort(locs, locs+n);
    int l=0; int m = 1e9;
    int ans=0;
    while(l!=m){
        int r = l+(m-l)/2;
        int counter = 0;
        ll end=0;
        for(int i=0; i<n; i++){
            if(locs[i]<=end){}
            else{
                counter++;
                end = 2*r + locs[i];
            }
        }
        if(counter<=k){
            if(m!=r){
            ans = r;
            m = r;}
            else break;
        }else{
            if(l!=r) l = r;
            else break;
        }
    }
    cout << ans;
}