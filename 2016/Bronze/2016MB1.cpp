#include <iostream>
using namespace std;

int between(int arr[],int n, int a, int b){
    int total=0;
    for(int i=0; i<n; i++){
        if (a<= arr[i] && arr[i]<=b) total++;
    }
    return total;
}

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n>>k;
    int arr[n];
    int curr=0;
    int ans=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]>curr) curr = arr[i];
    }

    for(int i=1; i<=curr-k; i++){
        int j= i+k;
        int val = between(arr, n,i, j);
        if(val > ans) ans = val;
    }
    cout << ans;
}