#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

map<int, pair<int, int> > meets;

bool equals(bool ar1[], bool ar2[], int k){
    for(int i=0; i<k; i++){
        if(ar1[i]!=ar2[i]) return false;
    }
    return true;
}

bool check(bool infected[], int n, int cow, int k){
    bool inf[n];
    int handsh[n];
    for(int i=0; i<n; i++){handsh[i]=0; inf[i]=false;}
    inf[cow] = true;
    for(int i=1; i<=250; i++){
        if(meets.count(i)==1){
            int x = meets[i].first-1; int y = meets[i].second-1;
            if(inf[x]) handsh[x]++;
            if(inf[y]) handsh[y]++;
            if(inf[x] && handsh[x]<=k) inf[y]=true;
            if(inf[y] && handsh[y]<=k) inf[x]=true;
        }
    }
    if(equals(infected, inf, n)) return true;
    return false;
}

int main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int n,t; string l;
    cin >> n>>t>>l;
    bool infected[n];
    for(int i=0; i<n; i++){
        if(l[i]=='1') infected[i]=true;
        else infected[i]=false;
    }
    
    for(int i=0; i<t; i++){
        int w; pair<int, int> v;
        cin >> w >> v.first >> v.second;
        meets[w]=v;
    }
    int counter=0;
    int maxk = 0;
    int mink = 300;
    for(int i=0; i<=n-1; i++){
        bool check2=false;
        for(int j=0; j<=250; j++){
            if(check(infected, n, i, j)){
                maxk = max(maxk, j);
                mink = min(mink, j);
                check2 = true;
            }
        }
        if(check2) counter++;
    }
    if(maxk == 250) cout << counter <<  " "<<mink << " Infinity";
    else cout << counter << " " << mink << " " << maxk;
}  