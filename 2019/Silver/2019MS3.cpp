#include <bits/stdc++.h>
using namespace std;

int leastx;
int maxx;
int maxy;
int leasty;
bool visited[100001]={false};
int loc[100001][2];
vector<int> adjs[100001];
void dfs(int node){
    visited[node]=true;
    maxx = max(loc[node][0], maxx);
    leastx = min(loc[node][0], leastx);
    maxy = max(loc[node][1], maxy);
    leasty = min(loc[node][1], leasty);
    for(auto elem: adjs[node]){
        if(visited[elem]==false) dfs(elem);
    }
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n,m; cin >> n>>m;
    for(int i=1; i<=n; i++) cin >> loc[i][0]>>loc[i][1];    
    for(int i=0; i<m; i++){
        int x,y; cin >>x>>y;
        adjs[x].push_back(y); adjs[y].push_back(x);
    }
    int ans=4e8;
    for(int i=1; i<=n; i++){
        if(visited[i]==false){
            maxx = 0; maxy =0; leasty = 1e8; leastx=1e8;
            dfs(i);
            ans = min(ans, 2*(maxx-leastx) + 2*(maxy-leasty));
        }
    }
    cout << ans;
}