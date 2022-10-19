#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >>s;
    int psumsc[200001], psumso[200001], psumsw[200001];
    psumsc[0]=0; psumso[0]=0; psumsw[0]=0;
    for(int i=1; i<=s.size(); i++){
        psumsc[i]=psumsc[i-1]; psumso[i]=psumso[i-1]; psumsw[i]=psumsw[i-1];
        if(s[i-1]=='C') psumsc[i]++;
        else if(s[i-1]=='O') psumso[i]++;
        else psumsw[i]++;
    }
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int x,y; cin >>x>>y;
        if((psumso[y]-psumso[x-1]+psumsc[y]-psumsc[x-1])%2==1 && (psumso[y]-psumso[x-1]+psumsw[y]-psumsw[x-1])%2==0) cout << "Y";
        else cout << "N";
    }
}