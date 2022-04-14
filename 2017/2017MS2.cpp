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
    for(int i=0; i<m-2;i++){
        for(int j=i+1; j<m-1; j++){
            for(int l=j+1; l<m; l++){
                bool checkk = true;
                for(int p=0; p<n; p++){
                    for(int q=0; q<n; q++){
                        if(spotty[p][i] == normal[q][i] && spotty[p][j] == normal[q][j] && spotty[p][l] == normal[q][l]) checkk=false;
                    }
                }
                if(checkk==true) total++;
            }
        }
    }
    cout << total;
}