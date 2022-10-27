#include <bits/stdc++.h>
using namespace std;

int depth[100000];
int bootdepth[100000];

bool greater1(int i, int j){return depth[i]<depth[j];}
bool greater2(int i, int j){return bootdepth[i]<bootdepth[j];}

int main(){
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n,b; cin >>n>>b;
    for(int i=0; i<n; i++) cin >> depth[i];
    int maxstep[b];
    for(int i=0; i<b; i++) cin >> bootdepth[i]>>maxstep[i];
    int orderb[b], ordern[n];
    map<int, pair<int, int> > dt;
    for(int i=0; i<n; i++) dt[i] = make_pair(i-1, i+1);
    for(int i=0; i<b; i++) orderb[i]=i;
    for(int i=0; i<n; i++) ordern[i]=i;
    sort(orderb, orderb+b, greater2);
    sort(ordern, ordern+n, greater1);
    int counter=n-1;
    int maxdiff = 1;
    map<int, int> ans;
    for(int i=0; i<b; i++){
        int bt = orderb[b-1-i];
        while(counter>=0 && depth[ordern[counter]]>bootdepth[bt]){
            int chekc = ordern[counter];
            dt[dt[chekc].second].first = dt[chekc].first;
            dt[dt[chekc].first].second = dt[chekc].second;
            maxdiff = max(maxdiff, dt[chekc].second - dt[chekc].first);
            counter--;
        }
        if(maxdiff<=maxstep[bt])ans[bt] = 1;
        else ans[bt]=0;
    }
    for(int i=0; i<b; i++) cout << ans[i]<<endl;
}