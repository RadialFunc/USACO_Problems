#include <iostream>
#include <set>
using namespace std;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin >> n;
    int othercow[n];
    set<int> other;
    for(int i=0; i<n; i++){cin >> othercow[i]; other.insert(othercow[i]);}
    set<int> bessie; 
    for(int i=1; i<=2*n; i++) if(other.count(i)==0) bessie.insert(i);
    int ans=0;
    for(int i=0; i<n; i++){
        int choose;
        if(*bessie.rbegin() < othercow[i])choose = *bessie.begin();
        else {choose = *bessie.upper_bound(othercow[i]); ans++;}
        bessie.erase(choose);
    }
    cout << ans;
}