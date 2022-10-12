#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll cows[n][2];
    ll exes[n];
    ll whys[n];
    for(int i=0; i<n; i++){
        cin >> exes[i] >> whys[i];
        cows[i][0] = exes[i]; cows[i][1] = whys[i];
    }
    sort(exes, exes+n); sort(whys, whys+n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(exes[j] == cows[i][0]){cows[i][0] = j; break;}
        }
        for(int j=0; j<n; j++){
            if(whys[j] == cows[i][1]){cows[i][1] = j; break;}
        }
    }
    bool ex[n+1][n+1];
    for(int i=0; i<n+1;i++){
        for(int j=0; j<n+1; j++){
            ex[i][j]=false;
        }
    }
    for(int i=0; i<n; i++){
        ex[cows[i][0]+1][cows[i][1]+1] = true;
    }
    int psums[n+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                psums[i][j]=0;
            }else{
                psums[i][j] = psums[i][j-1] + psums[i-1][j] - psums[i-1][j-1];
            }
            if(ex[i][j]) psums[i][j] +=1;
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int x1 = min(cows[i][0], cows[j][0]);
            int x2 = max(cows[i][0], cows[j][0]);
            int y1 = min(cows[i][1], cows[j][1]);
            int y2 = max(cows[i][1], cows[j][1]);
            int first, second;

            first = (psums[x1+1][y2+1]  - psums[x1+1][y1]);
            second = psums[n][y2+1]- psums[x2][y2+1]-psums[n][y1] + psums[x2][y1];
            ans += first*second;

        }
    }
    cout << ans+1;
}