#include <iostream>
using namespace std;

int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n; cin >> n;
    int scores[n]; for(int i=0; i<n; i++) cin >> scores[i];
    int sums[n+1]; sums[n]=0; 
    int mins[n+1]; mins[n]=10001;
    for(int i=n-1; i>=0; i--){
        sums[i] = sums[i+1]+scores[i];
        mins[i] = min(mins[i+1], scores[i]);
    }
    float highest =0;
    float store[n-2];
    for(int k=0; k<n-2; k++){
        store[k] = (sums[k+1] - mins[k+1])*1.0/(n-2-k);
        highest = max(store[k], highest);
    }
    for(int k=0; k<n-2; k++) if(store[k]==highest) cout << k+1 <<endl;
}