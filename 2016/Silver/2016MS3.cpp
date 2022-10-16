#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3001];
set<int> closed;
bool visited[3001];
void dfs(int node){
    visited[node] = true;
    for(auto elem: adj[node]){
        if(visited[elem]==false && closed.count(elem)==0) dfs(elem);
    }
}

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n,m; cin >> n>>m;
    for(int i=0; i<m; i++){
        int x,y; cin >>x>>y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    int closedo[n];
    for(int i=0; i<n; i++) cin >> closedo[i];
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++) visited[j] =false;
        dfs(closedo[n-1]);
        bool check = true;
        for(int j=1; j<=n; j++) if(closed.count(j) == 0 && visited[j]==false) check=false;
        if(check) cout << "YES"<<endl;
        else cout << "NO"<<endl;
        closed.insert(closedo[i]);
    }
}