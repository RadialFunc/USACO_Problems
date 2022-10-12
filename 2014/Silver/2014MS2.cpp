#include <iostream>
#include <cmath>
using namespace std;

int main(){
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n,k;
    cin >> n>>k;
    int grass[n][n];
    int psums[n][n+1];
    for(int i=0; i<n; i++){
        psums[i][0]=0;
        for(int j=0; j<n; j++){
            cin >> grass[i][j];
            psums[i][j+1] = psums[i][j] + grass[i][j];
        }
    }
    int highest=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int s=0;
            for(int l=0; l<n; l++){
                if(abs(l-i)<=k){
                    s += psums[l][min(n-1, j+k-abs(l-i))+1] - psums[l][max(0, j-k+abs(l-i))];
                }
            }
            highest = max(s, highest);
        }
    }
    cout << highest;
}