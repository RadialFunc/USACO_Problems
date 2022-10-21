#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int dfs(vector<int> adj[], int node, int color){
    visited[node] = color;
    for(auto elem: adj[node]){
        if(visited[elem]==-1) dfs(adj, elem, color);
    }
}

int main(){
    int t; cin >> t;
    for(int filler =0; filler<t; filler++){
        int n,m; cin >> n>>m;
        vector<int> adj[n+1]; 
        for(int i=0; i<=n+1; i++) visited[i]=-1;
        for(int i=0; i<m; i++){
            int x,y; cin >>x>>y;
            adj[x].push_back(y); adj[y].push_back(x);
        }
        int counter=0;
        for(int i=1; i<=n; i++){
            if(visited[i]==-1){dfs(adj, i, counter); counter++;}
        }
        if(counter==1) cout << 0 <<endl;
        else if(counter==2){
            if(visited[1]==visited[n]) cout << 0<<endl;
            else cout << 1<<endl;
        }else{
            bool check=false;
            for(int i=1; i<=n; i++){
                if(visited[i]==visited[1]){
                    if(visited[i-1] == visited[n] || visited[i+1]==visited[n]) check=true;
                }
            }
            if(visited[1]==visited[n]) cout << 0<<endl;
            else if(check) cout << 1<<endl;
            else cout << 2<<endl;
        }
    }
}