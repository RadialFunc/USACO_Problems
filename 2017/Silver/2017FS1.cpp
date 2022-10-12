#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c,n; cin >> c>>n;
    multiset<int> chick;
    for(int i=0; i<c; i++){int ch; cin>>ch; chick.insert(ch);}
    vector<pair<int, int> > cows;
    for(int i=0; i<n; i++){
        int a,b; cin >> a>>b; 
        cows.push_back(make_pair(b,a));
    }
    sort(cows.begin(), cows.end());
    int ans=0;
    for(int i=0; i<n; i++){
        auto find = chick.lower_bound(cows[i].second);
        if(*find <= cows[i].first && find != chick.end()){
            chick.erase(find);
            ans++;
        }
    }
    cout << ans;
}