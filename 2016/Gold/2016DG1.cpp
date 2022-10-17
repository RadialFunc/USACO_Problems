#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int cows[1000][2];
bool visited[1000];
int n;
void dfs(vector<int> adj[], int node){
    visited[node]=true;
    for(auto elem: adj[node]){
        if(!visited[elem]) dfs(adj, elem);
    }
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    ll ans = 1250000000;
    ll l=0; ll h =1250000000;
    for(int i=0; i<n; i++) cin >> cows[i][0]>>cows[i][1];
    while(l!=h){
        for(int i=0; i<n; i++) visited[i]=false;
        vector<int> adj[n];
        ll X = (l+h)/2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(pow(cows[i][0]-cows[j][0], 2) + pow(cows[i][1]-cows[j][1],2) <=X){
                    adj[i].push_back(j); adj[j].push_back(i);
                }
            }
        }
        dfs(adj, 0);
        bool check=true;
        for(int i=0; i<n; i++) if(!visited[i]) check=false;
        if(check){
            ans = min(X, ans);
            if(h==X) break;
            else h=X;
        }else{
            if(l==X) break;
            else l=X;
        }
    }
    cout << ans;
}