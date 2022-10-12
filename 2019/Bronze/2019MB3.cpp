#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <map>
using namespace std;

bool check(vector<vector<string> > cows){
    set<string> diff;
    multiset<string> all;
    if(cows.size()==0) return true;
    if(cows.size()==1) return true;
    for(int i=0; i<cows.size(); i++){
        for(int j=0; j<cows[i].size(); j++){
            diff.insert(cows[i][j]);
            all.insert(cows[i][j]);
        }
    }
    int k=0;
    for(auto val: diff){
        if(all.count(val)> k) k=all.count(val);
    }
    string trait;
    for(auto val:diff){
        if(all.count(val)==k){trait = val; break;}
    }
    vector<vector<string> > hastrait;
    vector<vector<string> > notrait;
    for(int i=0; i<cows.size(); i++){
        bool in = false;
        for(int j=0; j<cows[i].size(); j++){
            if(cows[i][j]==trait) in=true;
        }
        if(in) hastrait.push_back(cows[i]);
        else notrait.push_back(cows[i]);
    }
    for(int i=0; i<hastrait.size(); i++){
        for(int j=0; j<hastrait[i].size(); j++){
            for(int l=0; l<notrait.size(); l++){
                for(int p=0; p<notrait[l].size();p++){
                    if(hastrait[i][j] ==notrait[l][p]){return false; }
                }
            }
        }
    }
    if(hastrait.size()==0) return false;
    for(int i=0; i<hastrait.size();i++){
        for(int j=0; j<hastrait[i].size(); j++){
            if(hastrait[i][j]==trait){
                vector<string>::iterator it = hastrait[i].begin()+j;
                hastrait[i].erase(it);
            }
        }
    }
    return (check(hastrait) && check(notrait));
    
}

int main(){
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<string> > cows;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        vector<string> cow;
        for(int j=0; j<k; j++){string trait; cin >> trait; cow.push_back(trait);}
        cows.push_back(cow);
    }
    bool th = check(cows);
    if(th) cout << "yes";
    else cout << "no";
}