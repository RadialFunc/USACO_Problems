#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<pair<int, int> > adj[100001];
void dfs(int node, int w, vector<int>& visited, int count){
    visited[node]=count;
    for(auto elem: adj[node]){
        if(visited[elem.first] ==-1 && elem.second >=w) dfs(elem.first, w, visited, count);
    }
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n,m; cin >> n>>m;
    bool check=true;
    int p[n+1];for(int i=1; i<n+1; i++){cin >>p[i]; if(p[i]!=i) check=false;}
    if(check){cout << -1; return 0;}
    for(int i=0; i<m; i++){
        int x,y,w; cin >> x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    ll l = 1; ll h = 1e9;
    int ans = 0;
    while(l!=h){
        ll w = (l+h)/2;
        bool works = true;
        vector<int> visited;
        for(int i=0; i<=n; i++)visited.push_back(-1);
        for(int i=1; i<= n; i++){
            if(visited[i]==-1){
            dfs(p[i], w, visited, i);
            }
        }
        for(int i=1; i<=n; i++){
            if(visited[i] != visited[p[i]]) works=false;
        }
        if(works){
            ans = w;
            if(l==w) break;
            else l=w;
        }else{
            if(h==w) break;
            else h=w;
        }
    }
    cout << ans;
}