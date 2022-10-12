#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > rankings;

bool consistent(int a,int b, int n, int k){
    bool beats=true;
    bool fin = true;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            if (rankings[i][j]==a){
                beats=true;
            }else if(rankings[i][j]==b){
                beats=false;
            }

        }
        if (beats==false){
            fin=false;
            break;
        }
    }    
    return fin;
}

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n,k;
    cin >>k>>n;
    for (int i=0; i<k; i++){
        vector<int> session;
        for(int j=0; j<n; j++){
            int l;
            cin >> l;
            session.push_back(l);
        }
        rankings.push_back(session);
    }
    int total=0;
    for(int i=1; i<n; i++){
        for (int j=i+1; j<n+1; j++){
            if (consistent(i,j,n,k))total++;
            if (consistent(j,i,n,k)) total++;
        }
    }
    cout << total;
}