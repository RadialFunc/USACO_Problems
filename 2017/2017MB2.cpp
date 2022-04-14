#include <iostream>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n,m;
    cin >> n>>m;
    int spotty[n][m];
    int normal[n][m];
    for(int i=0; i<n; i++){
        string genes;
        cin >> genes;
        for(int j=0; j<m; j++){
            spotty[i][j] = int(genes[j]);
        }
    }
    for(int i=0; i<n; i++){
        string genes;
        cin >> genes;
        for(int j=0; j<m; j++){
            normal[i][j] = int(genes[j]);
        }
    }
    int total=0;
    for(int i=0; i<m;i++){
        int vals[n];
        for(int j=0; j<n; j++){
            vals[j]= spotty[j][i];
        }
        bool checkk = true;
        for(int j=0; j<n; j++){
            for(int l=0; l<n; l++){
                if(spotty[l][i] == normal[j][i]) checkk=false;
            }
        }
        if (checkk==true) total++;
    }
    cout << total;
}