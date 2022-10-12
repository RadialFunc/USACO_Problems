#include <iostream>
#include <algorithm>
using namespace std;

int pass(int a[], int i, int n){
    if(i==0) return 1;
    else if(i==n-1) return n-2;
    else if(a[i] - a[i-1] <= a[i+1] - a[i]) return i-1;
    else return i+1;
}

int main(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int pss[n];
    for(int i=0; i<n; i++) pss[i]=0;
    for(int i=0; i<n; i++){
        pss[pass(a, i, n)] +=1;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(pss[i]==0) ans++;
        else if(i<n-1 && pss[i]==1 && pss[i+1] == 1 && pass(a, i, n) == i+1 && pass(a, pass(a,i,n), n)==i) ans++;
    }
    cout << ans;
}