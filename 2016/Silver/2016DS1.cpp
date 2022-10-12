#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q; cin >> n>>q;
    vector<int> bales;
    for(int i=0; i<n; i++){
        int k; cin >> k; bales.push_back(k);
    }
    sort(bales.begin(), bales.end());
    for(int i=0; i<q; i++){
        int s,e; cin >> s>>e;
        cout << upper_bound(begin(bales), end(bales), e) - lower_bound(begin(bales), end(bales), s)<<endl;
    }
}