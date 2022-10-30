#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> x;
int n;

bool checkleft(ll loc, ll radius){
    if(loc == *x.begin()) return true;
    int change = *x.lower_bound(loc-radius);
    if(change == loc) return false;
    else return checkleft(change, radius-2);
}

bool checkright(ll loc, ll radius){
    if(loc == *x.rbegin()) return true;
    int change = *(--x.upper_bound(loc+radius));
    if(change == loc) return false;
    else return checkright(change, radius-2);
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++){ll s; cin >> s; x.insert(2*s);}
    ll l=0; ll h= 1e9;
    ll ans = 1e9;
    while(l!=h){
        ll r = (l+h)/2;
        ll first = *x.begin();  ll last = *x.rbegin();
        while(first!= last){
            ll pos = (first+last)/2;
            bool a = checkleft(pos, r); bool b = checkright(pos,r);
            if(a==b){
                if(a) ans = min(ans, r);
                break;
            }else{
                if(a){
                    if(first==pos) break;
                    first=pos;
                }
                else{
                    if(last==pos) break;
                    last=pos;
                }
            }
        }
        if(ans==r){if(h==r) break; h=r;}
        else{if(l==r) break; l=r;}
    }
    if(ans%2==0){
        cout << ans/2<<".0";
    }else{
        cout << ans/2<<".5";
    }
}