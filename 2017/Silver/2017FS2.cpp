#include <iostream>
#include <set>

using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n,k,b; cin >> n>>k>>b;
    set<int> broken;
    for(int i=0; i<b; i++){
        int l;
        cin >>l;
        broken.insert(l);
    }
    int brokewith[n+1];
    brokewith[0]=0;
    for(int i=1; i<n+1; i++){
        brokewith[i] = brokewith[i-1];
        if(broken.count(i) ==1) brokewith[i]++; 
    }
    int least = n;
    for(int i=0; i<=n-k; i++){
        least = min(least, brokewith[i+k]- brokewith[i]);
    }
    cout << least;
}