#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n,t; cin >> n>>t;    
    int d[n]; 
    for(int i=0; i<n; i++) cin >> d[i];
    int l=1; int m = n;
    int ans=0;
    while(l!=m){
        int k = (l+m)/2;
        multiset<int> possible;
        for(int i=0; i<n; i++){
            if(i<k) possible.insert(d[i]);
            else{
                int change = *possible.begin();
                possible.erase(possible.begin());
                possible.insert(change + d[i]);
            }
        }
        int time = *possible.rbegin();
        if(time <= t){
            ans = k;
            if(m==k) break;
            else m=k;
        }else{
            if(l==k) break;
            else l=k;
        }
    }
    cout << ans;
}
