#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int mx = max(a[n-2]-a[0] , a[n-1]-a[1])-(n-2);
    int least = n;
    int i=0; int j=0;
    if((a[n-2]-a[0]==n-2 && a[n-1]-a[n-2]>2)) least =2;
    else if((a[n-1]-a[1]==n-2 && a[1]-a[0]>2)) least=2;
    else{
    while(i<n){
        while(a[j+1] - a[i]<n && j<n-1) j++;
        least = min(least, n-(j+1-i));
        i++;
    }
    }
    cout << least <<endl<<mx;
}