#include <iostream>
#include <algorithm>
using namespace std;
using ll =long long;
int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n; ll k; cin >> n>>k;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int start2, end2; start2 =0; end2=0;
    int ans =0;
    int maxunder[n];
    for(int i=0; i<n; i++) maxunder[i]=0;
    while(start2<n && end2<n){
        while(arr[end2]-arr[start2] <=k){
            maxunder[end2] = max(maxunder[end2], end2-start2+1);
            end2++;
        }
        end2--;
        
        start2++;
    }
    int maxmaxunder[n];
    maxmaxunder[0] = maxunder[0];
    for(int i=1; i<n; i++) maxmaxunder[i] = max(maxmaxunder[i-1], maxunder[i]);
    for(int i=0; i<n; i++){
        if(maxunder[i] == i+1) ans = max(ans, maxunder[i]);
        else ans = max(maxunder[i] + maxmaxunder[i-maxunder[i]], ans);
    }
    cout << ans;
}