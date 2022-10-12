#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > adj[5001];
bool visited[5001];

void dfs(int ver, int k){
    visited[ver] = true;
    for(auto conn: adj[ver]){
        if(!visited[conn.first] && conn.second >= k){
            dfs(conn.first, k);
        }
    }
}

int solve(int k, int v){
    for(int i=0; i<5001; i++) visited[i]=false;
    dfs(v, k);
    int count=0;
    for(int i=0; i<5001; i++) if(visited[i]) count++;
    return count-1;
}
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n>>q;

    for(int i=0; i<n-1; i++){
        int a,b,c; cin >> a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a,c));
    }

    for(int i=0; i<q; i++){
        int k, v;
        cin >> k>>v;
        cout << solve(k,v)<<endl;
    }
}