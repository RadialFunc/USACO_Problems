#include <iostream>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int p[n+1], h[n+1], s[n+1];
    p[0]=0; h[0]=0; s[0]=0;
    for(int i=0; i<n; i++){
        char move; cin >> move;
        p[i+1]=p[i]; s[i+1]=s[i]; h[i+1]=h[i];
        if(move == 'P') s[i+1]++;
        else if(move == 'H') p[i+1]++;
        else h[i+1]++;
    }
    int greatest = 0;
    for(int i=0; i<n; i++){
        greatest = max(greatest, max(max(s[i+1], h[i+1]), p[i+1]) + max(max(s[n]-s[i+1], h[n]-h[i+1]), p[n]-p[i+1]));
    }
    cout << greatest;
}