#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >>n;
    int cows[n];
    bool goup;
    for(int i=0; i<n; i++) cin >> cows[i];
    int naughty = -1;
    for(int i=1; i<n; i++){
        if(cows[i]<cows[i-1]){
            if(i==1){
                naughty = i-1;
                goup = true;
            }else if (i==n-1){
                naughty = i;
                goup = false;
            }else{
                if(cows[i-1] >= cows[i-2] && cows[i-1]<= cows[i+1]){naughty = i; goup = false;}
                else {naughty=i-1; goup= true;}
            }
        }
    }
    int sortedcows[n];
    for(int i=0; i<n; i++) sortedcows[i] = cows[i];
    if(naughty==-1) cout << 0;
    else{
         set<int> s;
         if(goup==true){
            for(int i=naughty+1; i<n; i++){
                if(cows[i]<cows[naughty]) s.insert(cows[i]);
            }
         }else{
            for(int i=naughty-1; i>=0; i--){
                if(cows[i]>cows[naughty])s.insert(cows[i]);
            }
         }
        int ans=0;
        for (int element : s) {
	        ans++;
        }
        cout << ans;
    }
}