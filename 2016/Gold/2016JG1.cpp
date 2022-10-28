#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    ll x[n];
    for(int i=0; i<n; i++){cin >>x[i]; x[i]*=2;}
    ll l=0; ll h= 1e9;
    while(l!=h){
        ll r = (l+h)/2;
        ll first = x[0];  ll last = x[n-1];
        while(first!= last){
        }
    }
}