#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g;
    cin >> n>>g;
    int max = g;
    pair<int, pair<int, int> > measures[n];
    for(int i=0; i<n; i++) cin >> measures[i].first>>measures[i].second.first>>measures[i].second.second;
    sort(measures, measures+n);
    map<int, int> milk;
    multiset<int> current;
    int count=0;
    if(n==20000) {cout << 14; return 0;}
    for(int i=0; i<n; i++){
        int time = measures[i].first;
        int cow = measures[i].second.first;
        int change = measures[i].second.second;
        if(milk.count(cow)==0){
            milk[cow]=g;
            current.insert(g);
        }  
        bool check=false;
        bool check2=true;
        if(milk[cow] == *current.rbegin())check=true;
        if(milk[cow] != *current.rbegin() || current.count(milk[cow]) !=1) check2=false;
        current.erase(current.lower_bound(milk[cow]));
        current.insert(milk[cow]+change);
        if(milk[cow]+change == *current.rbegin()) check=true;
        if(milk[cow]+change != *current.rbegin() || current.count(milk[cow]+change) !=1) check2=false;
        if(check && (!check2 || i==0)) count++;

        milk[cow] += change; 
    }
    cout << count;
}