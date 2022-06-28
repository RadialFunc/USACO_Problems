#include <iostream>
#include <vector>
using namespace std;

int visited[101];
vector<int> adj[101];


void dfs(int node){
    visited[node]=true;
    for(int next: adj[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a>>b;
        adj[b].push_back(a);
    }
    bool finalcheck=true;
    for(int i=1; i<n+1; i++){
        dfs(i);
        bool check=true;
        for(int j=1; j<=n; j++){
            if(visited[j] != true) check=false;
        }
        if(check==true){
            cout << i;
            finalcheck=false;
            break;
        }else{
            for(int j=1; j<=n; j++) visited[j]=false;
        }
    }
    if(finalcheck) cout << -1;
}