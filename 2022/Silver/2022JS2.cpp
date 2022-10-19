#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int h[n];
    for(int i=0; i<n; i++) cin >> h[i];
    map<int, int> ntoi;
    map<int, pair<int, int> > adjacent;
    for(int i=0; i<n; i++){
        ntoi[h[i]] = i;
        if(i==0) adjacent[h[i]].first = -1;
        else adjacent[h[i]].first = h[i-1];

        if(i==n-1) adjacent[h[i]].second=-1;
        else adjacent[h[i]].second = h[i+1];
    }
    long long answer=0;
    for(int i=1; i<=n; i++){
        if(adjacent[i].first!=-1) answer += ntoi[i] - ntoi[adjacent[i].first] +1;
        if(adjacent[i].second !=-1) answer+= ntoi[adjacent[i].second] - ntoi[i]+1;
        adjacent[adjacent[i].second].first = adjacent[i].first;
        adjacent[adjacent[i].first].second = adjacent[i].second;
    }
    cout << answer;
}