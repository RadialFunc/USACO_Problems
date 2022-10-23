#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int dfs(vector<int> adj[], int node, int color){
    visited[node] = color;
    for(auto elem: adj[node]){
        if(visited[elem]!=color) dfs(adj, elem, color);
    }
}

int main(){
    int t; cin >> t;
    for(int filler =0; filler<t; filler++){
        int n,m; cin >> n>>m;
        vector<int> adj[n]; 
        for(int i=0; i<n; i++) visited[i]=i;
        for(int i=0; i<m; i++){
            int x,y; cin >>x>>y;
            x--; y--;
            adj[x].push_back(y); adj[y].push_back(x);
        }
        for(int i=0; i<n; i++){
            if(visited[i]==i) dfs(adj, i, i); 
        }

        vector<vector<int> > coloring(n);
        for(int i=0; i<n; i++) coloring[visited[i]].push_back(i);
        vector<long long> storecost(n, 1e9);
        vector<long long> storecost2(n, 1e9);
        int p21 = 0;
        int p22 = 0;
        for(int i = 0; i < n; i++) {
            while(p21 < coloring[visited[0]].size()) {
                storecost[visited[i]] = min(storecost[visited[i]], (long long)abs(i - coloring[visited[0]][p21]));
                if(coloring[visited[0]][p21] < i) p21++;
                else break;
            }
            if(p21) p21--;
            while(p22 < coloring[visited[n-1]].size()) {
            storecost2[visited[i]] = min(storecost2[visited[i]], (long long)abs(i - coloring[visited[n-1]][p22]));
            if(coloring[visited[n-1]][p22] < i) p22++;
            else break;
            }
            if(p22) p22--;
        }
        long long ans=1e18;
        for(int i = 0; i < n; i++) ans = min(ans, storecost[i]*storecost[i] + storecost2[i]*storecost2[i]);
        if(visited[0] != visited[n-1]) cout << ans<<endl;
        else cout << 0<<endl;
    }
}