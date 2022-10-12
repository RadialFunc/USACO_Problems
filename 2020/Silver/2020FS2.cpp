#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;
using ll = long long;


int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; cin >> n;
    map<int, vector<int> > xtoy;
    map<int, vector<int> > ytox;
    pair<int, int> coords[n];
    for(int i=0; i<n; i++){
        int x,y; cin >> x>>y;
        xtoy[x].push_back(y);
        ytox[y].push_back(x);
        /*sort(xtoy[x].begin(), xtoy[x].end());
        sort(ytox[y].begin(), ytox[y].end());*/
        coords[i].first = x; coords[i].second=y;
    }
    for(auto& [key,val]: ytox){
        sort(ytox[key].begin(), ytox[key].end());
    }
    for(auto& [key,val]: xtoy){
        sort(xtoy[key].begin(), xtoy[key].end());
    }
    map<int, map<int, ll> > psumsy;
    for(auto& [key,val]: ytox){
        for(auto m: val){
            psumsy[key][val[0]] += abs(m-val[0]);
        }
        for(int i=1; i<val.size(); i++){
            psumsy[key][val[i]] = psumsy[key][val[i-1]] + (val[i]-val[i-1]) * ((i-1) - (val.size()-i-1));
        }
    }
    map<int, map<int, ll> > psumsx;
    for(auto& [key,val]:xtoy){
        for(auto m: val){
            psumsx[key][val[0] ] += abs(m-val[0]);
        }
        for(int i=1; i<val.size(); i++){
            psumsx[key][val[i] ] = psumsx[key][val[i-1]] + (val[i]-val[i-1]) * ((i-1) - (val.size()-i-1));
        }
    }
    ll sm=0;
    ll MOD = 1000000007;
    for(int i=0; i<n; i++){
        sm += psumsx[coords[i].first][coords[i].second] * psumsy[coords[i].second][coords[i].first];
        
    }
    
    cout << sm % MOD;
}