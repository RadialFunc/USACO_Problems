#include <iostream>
#include <set>
using namespace std;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    int othercow[n];
    set<int> other;
    for(int i=0; i<n; i++){cin >> othercow[i]; other.insert(othercow[i]);}
    set<int> bessie1;
    set<int> bessie2; 
    int count=0;
    for(int i=1; i<=2*n; i++){
        if(other.count(i)==0&& count <n/2) bessie2.insert(i);
        if(other.count(i)==0&& count >=n/2) bessie1.insert(i);
        if(other.count(i)==0) count++;
    }
    int ans=0;
    for(int i=0; i<n/2; i++){
        int choose;
        if(*bessie1.rbegin() < othercow[i])choose = *bessie1.begin();
        else {choose = *bessie1.upper_bound(othercow[i]); ans++;}
        bessie1.erase(choose);
    }
    for(int i=n/2; i<n; i++){
        int choose;
        if(*bessie2.begin() > othercow[i])choose = *bessie2.rbegin();
        else if(*bessie2.rbegin() <othercow[i]){ans++; choose = *bessie2.rbegin();}
        else {choose = *(--bessie2.upper_bound(othercow[i])); ans++;}
        bessie2.erase(choose);
    }
    cout << ans;
}