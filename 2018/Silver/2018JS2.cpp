#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
bool comparison(pair<int, int> first, pair<int, int> second){return first.first >second.first;}

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n>>m>>r;
    int milk[n];
    pair<int, int> shops[m];
    int rentals[r];
    for(int i=0; i<n; i++) cin >> milk[i];
    for(int i=0; i<m; i++) cin >> shops[i].second>>shops[i].first;
    for(int i=0; i<r; i++) cin >> rentals[i];
    sort(milk, milk+n, greater<int>());
    sort(shops, shops+m, comparison);
    sort(rentals, rentals+r, greater<int>());
    ll rent[n+1]; rent[0]=0;
    for(int i=1; i<n+1; i++){
        rent[i] = rent[i-1];
        if(i-1 < r) rent[i] += rentals[i-1];
    }
    ll shop[n+1]; shop[0]=0;
    int shopcnt = 0;
    for(int i=1; i<n+1; i++){
        int mil  = milk[i-1];
        shop[i] = shop[i-1];
        while(mil >0 && shopcnt < m){
            if(shops[shopcnt].second <= mil){
                shop[i] += shops[shopcnt].first * shops[shopcnt].second;
                mil -= shops[shopcnt].second;
                shopcnt++;
            }else{
                shop[i]+= mil * shops[shopcnt].first;
                shops[shopcnt].second -= mil;
                mil =0;
            }
        }
    }
    ll earn=0;
    for(int i=0; i<=n; i++){
        earn = max(earn, shop[i] + rent[n-i]);
    }
    cout << earn;
}