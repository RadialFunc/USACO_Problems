#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;


int main(){
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> cows[n];

    for(int i=0; i<n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows, cows+n);
    int r=1000001;
    for(int i=1; i<n-1; i++){
        if(cows[i].second ==1 && cows[i-1].second ==0) r = min(r, cows[i].first - cows[i-1].first-1);
        if(cows[i].second ==1 && cows[i+1].second ==0) r = min(r, -cows[i].first + cows[i+1].first-1);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(cows[i].second==1){
            ans++;
            while(cows[i+1].first-cows[i].first<=r) i++;
        }
    }
    cout << ans;
}