#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

using ll = long long;

struct life{
    bool start; ll time; int guard;
    
};

bool cmp(const life& x, const life& y) { return x.time < y.time; }

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    life lifeguards[2*n];
    for(int i=0; i<n; i++){
        life g1, g2;
        g1.start = true; g1.guard = i;
        g2.start = false; g2.guard=i;
        cin >> g1.time>>g2.time;
        lifeguards[2*i] = g1; lifeguards[2*i+1] = g2;
    }
    sort(lifeguards, lifeguards+2*n, cmp);
    ll total=0;
    ll lost[n];
    for(int i=0; i<n; i++) lost[i]=0;
    set<int> active;
    for(int i=0; i<2*n; i++){
        if(active.size()>0){
            total+= lifeguards[i].time - lifeguards[i-1].time;
        }if(active.size()==1){
            lost[*active.begin()]+= lifeguards[i].time - lifeguards[i-1].time;
        }
        if(lifeguards[i].start)active.insert(lifeguards[i].guard);
        else active.erase(lifeguards[i].guard);
    }
    ll least = 1000000000;
    for(int i=0; i<n; i++){
        least = min(least, lost[i]);
    }
    cout << total-least;
}   