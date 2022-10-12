#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
struct life{
    ll start;  ll end; int peak;
};

bool cmp(const life& x, const life& y) {
    if(x.start != y.start) return x.start<y.start;
    return x.end > y.end;
}

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    life mts[n];
    for(int i=0; i<n; i++){
        life l1;
        ll a,b;
        cin >> a>>b;
        l1.start = a-b;
        l1.end = a+b;
        l1.peak = i;
        mts[i]=l1;
    }
    sort(mts, mts+n, cmp);
    int count =0;
    set<int> active;
    ll checkk[n];
    ll highest =0;
    for(int i=0; i<n; i++){
        if(mts[i].end > highest) count++;
        highest = max(highest, mts[i].end);
    }
    cout << count;
}