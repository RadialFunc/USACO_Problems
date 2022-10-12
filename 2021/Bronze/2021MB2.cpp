#include <iostream>
using namespace std;

int findcow(string cow, string cows[], int n){
    for(int i=0; i<n; i++){
        if(cows[i] == cow) return i;
    }
}

int main(){
    int k,n; cin >> k>>n;
    string cows[n];
    string publish[k][n];
    for(int i=0; i<n; i++) cin >> cows[i];
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++) cin >> publish[i][j];
    }
    char ans[n][n];
    for(int i=0; i<k; i++){
        for(int j=0; j<n-1; j++){
            bool alphab = true;
            for(int l=j+1; l<n; l++){
                if(publish[i][l].compare(publish[i][l-1])>0 && alphab==true) alphab=true;
                else alphab=false;
                if(!alphab)ans[findcow(publish[i][l], cows, n)][findcow(publish[i][j], cows, n)]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cout << "B";
            else if(ans[j][i]==1) cout << 0;
            else if(ans[i][j]==1) cout << 1;
            else cout << "?";
        }
        cout << endl;
    }

}