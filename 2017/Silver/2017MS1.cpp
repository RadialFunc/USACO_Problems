#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    map<int, int> types;
    int n; cin >> n;
    int typ[n];
    for(int i=0; i<n; i++){
        int t, cn; cin >> t>>cn;
        types[cn]=t;
        typ[i] = cn;
    }
    sort(typ, typ+n);
    int i=0; int j=n-1;
    int ans=0;
    while(i<=j){
        if(types[typ[i]] >= types[typ[j]]){
            types[typ[i]] -= types[typ[j]];
            types[typ[j]] = 0; 
        }else{
            types[typ[j]] -= types[typ[i]];
            types[typ[i]]=0;
        }
        ans = max(typ[i]+typ[j], ans);
        if(types[typ[i]]==0) i++;
        if(types[typ[j]]==0) j--;
    }
    cout << ans;
}