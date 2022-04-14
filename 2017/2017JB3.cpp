#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > tipped;

int add(int n){
    if(n==0) return 0;
    int total=0;
    if(tipped[n-1][n-1] == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(tipped[i][j]==0) tipped[i][j]=1;
                else if(tipped[i][j]==1) tipped[i][j]=0;
            }
        }
        total++;
    }
    for(int k=1; k<n; k++){
        int i = n-1-k;
        int j= n-1;
        if(tipped[i][j] == 1){
            total++;
            for(int p=0; p<=i; p++){
                for(int q =0; q<=j; q++){
                    if(tipped[p][q]==0) tipped[p][q]=1;
                    else if(tipped[p][q]==1) tipped[p][q]=0;   
                }
            }
        }
        if(tipped[j][i] == 1){
            total++;
            for(int p=0; p<=j; p++){
                for(int q =0; q<=i; q++){
                    if(tipped[p][q]==0) tipped[p][q]=1;
                    else if(tipped[p][q]==1) tipped[p][q]=0;   
                }
            }
        }
    }
    return total+add(n-1);
}

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> rw; 
        string k;
        cin >> k;
        for(int j=0; j<n; j++){
            rw.push_back(k[j]-'0');
        }
        tipped.push_back(rw);
    }
    cout << add(n);

}