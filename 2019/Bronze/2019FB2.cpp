#include <iostream>
using namespace std;
#include <vector> 
#include <set>

int main(){
    freopen("revegetate.in", "r",stdin);
    freopen("revegetate.out", "w", stdout);
    int n,m;
    cin >> n>>m;
    int plant[n];
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0; i<n; i++){
        set<int> used;
        for(int j=0; j<adj[i].size(); j++){
            if(adj[i][j]<i) used.insert(plant[adj[i][j]]);
        }
        bool check = true; int cnt = 1;
        while(check){
            if(used.count(cnt) ==0) {check=false; plant[i]=cnt;}
            else cnt++;
        }
    }
    for(int i=0; i<n; i++) cout << plant[i];
}