#include <iostream>
using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin >>n;
    int swaps[n][3];
    for(int i=0; i<n; i++) cin >> swaps[i][0]>>swaps[i][1] >> swaps[i][2];
    int high=0;
    for(int i=0; i<3; i++){
        int current = i+1;
        int total=0;
        for(int j=0; j<n; j++){
            if(swaps[j][0]==current) current = swaps[j][1];
            else if(swaps[j][1] == current) current=swaps[j][0];
            if(current == swaps[j][2]) total++;
        }
        if(total>high) high=total;
    }
    cout << high;
}