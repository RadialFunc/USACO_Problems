#include <iostream>
#include <map>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    int a[n+1]; a[0]=0;
    map<int, int> first; map<int, int> last;
    for(int i=0; i<n; i++){
        int j; cin >> j;
        a[i+1] = (a[i] + j)%7;
        last[a[i+1]] = i;
        if(first.count(a[i+1])==0) first[a[i+1]] = i;
    }
    int larg = 0;
    for(int i=0 ;i<7; i++){
        if(first.count(i) == 1 && last.count(i)==1) larg = max(larg, last[i] - first[i]);
    }
    cout << larg;
}