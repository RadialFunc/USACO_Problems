#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second =i;
    }
    sort(arr, arr+n);
    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(ans, arr[i].second-i);
    }
    cout << ans+1;
}