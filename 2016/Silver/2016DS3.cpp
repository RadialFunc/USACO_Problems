#include <bits/stdc++.h>
using namespace std;

vector<int> adj[201];
bool visited[201];

void dfs(int node){
    visited[node] = true;
    for(auto elem: adj[node]){
        if(visited[elem]==false) dfs(elem);
    }
}
int main(){
    int n; cin >> n;
    int cows[n][3];
    for(int i=0; i<n; i++) cin >> cows[i][0]>>cows[i][1]>>cows[i][2];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cows[i][2]>= sqrt(pow(cows[i][0]-cows[j][0],2) + pow(cows[i][1]-cows[j][1], 2))) adj[i].push_back(j);
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) visited[j]=false;
        dfs(i);
        int count =0;
        for(int j=0; j<n; j++) if(visited[j]) count++;
        ans = max(ans,count);
    }
    cout << ans;
}