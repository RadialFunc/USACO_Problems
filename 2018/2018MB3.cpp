#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <set>

map<string, bool> visited;

void dfs(string c, map<string, set<string> > adj){
    visited[c] = true;
    if(adj.count(c)==1){
        for(auto val: adj[c]){
            if(!visited[val]) dfs(val, adj);
        }
    }
}


int main(){
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    map<string, set<string> > babies;
    map<string, string> mommies;
    map<string, set<string> > adj;
    int n; string c1,c2;
    cin >> n>>c1>>c2;
    for(int i=0; i<n; i++){
        string x,y;
        cin >> x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
        babies[x].insert(y);
        mommies[y]=x;
    }
    for(auto val: babies){
        if(val.second.count(c1)==1 && val.second.count(c2)==1){cout << "SIBLINGS";return 0;}
    }
    string currentcow = c1;
    int counter=-1;
    while(mommies.count(currentcow) == 1){
        currentcow = mommies[currentcow];
        if(currentcow==c2){
            if(counter==-1) cout << c2 <<" is the mother of " << c1;
            else{
                cout << c2 << " is the ";
                for(int i=0; i<counter; i++) cout << "great-";
                cout << "grand-mother of " << c1;
            }
            return 0;
        }
        else if(mommies.count(c2)==1 && currentcow == mommies[c2]){
            cout << c2 << " is the ";
            for(int i=0; i<counter; i++){
                cout << "great-";
            }
            cout << "aunt of " << c1;
            return 0;
        }
        counter++;
    }

    currentcow = c2;
    counter=-1;
    while(mommies.count(currentcow) == 1){
        currentcow = mommies[currentcow];
        if(currentcow==c1){
            if(counter==-1) cout << c1 <<" is the mother of " << c2;
            else{
                cout << c1 << " is the ";
                for(int i=0; i<counter; i++) cout << "great-";
                cout << "grand-mother of " << c2;
            }
            return 0;
        }
        else if(mommies.count(c1)==1 && currentcow == mommies[c1]){
            cout << c1 << " is the ";
            for(int i=0; i<counter; i++){
                cout << "great-";
            }
            cout << "aunt of " << c2;
            return 0;
        }
        counter++;
    }
    
    dfs(c1, adj);
    if(visited[c2]) cout << "COUSINS";
    else cout << "NOT RELATED";

}