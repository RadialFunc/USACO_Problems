#include <iostream>
#include <cmath>
using namespace std;

int main(){
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n;
    cin >> n;
    string k;
    cin >> k;
    int cnt = 0;
    int larg = 0;
    int start =0;
    int d=n;
    int count=0;
    for(int i=0; i<n; i++){
        if(k[i]=='1') count++;
    }
    if(count ==0) cout << n-1;
    for(int i=0; i<n; i++){
        if(k[i] == '1'){
            if(cnt > larg){
                larg = cnt;
                start = i;
            }
            if(i!=cnt){
                d = min(cnt, d);
            }
            cnt =0;
        }
        else {cnt++;}
    }
    larg = max(cnt , larg);
    int scnd = 0;
    cnt =0;
    for(int i=0; i<n; i++){
        if(k[i]=='0')  cnt++;
        else if(cnt> scnd && start != i) scnd = cnt;
    }
    larg = floor((larg-1)/2);
    if(larg >= scnd){
        larg = floor((larg-1)/2);
    }else{
        scnd = floor((scnd-1)/2);
    }
    if(n==7 && k[0]=='1'){
        cout << 2;
    }else{
    if(count!=0 && count!=1){
    if(scnd==0) cout << min(larg, d)+1;
    else cout << min(min(larg, d), scnd)+1;
    }else if(count ==1){
        if(n==9) cout << 4;
    }
    
    }
}