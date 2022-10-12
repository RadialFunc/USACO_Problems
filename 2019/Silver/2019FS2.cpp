#include <iostream>
using namespace std;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int cells[1001][1001]= {0};
    int n,k;
    cin >> n>>k;
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2; cin >> x1>>y1>>x2>>y2;
        cells[x1][y1]++; cells[x2][y2]++;
        cells[x1][y2]--; cells[x2][y1]--;
    }
    int count=0;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            if(i!=0)cells[i][j] +=cells[i-1][j] ;
            if(j!=0) cells[i][j] += cells[i][j-1];
            if(i!=0 && j!=0) cells[i][j] -= cells[i-1][j-1];

            if(cells[i][j]==k) count++;
        }
    }
    cout << count;
}