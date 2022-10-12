#include <iostream>
#include <utility>
using namespace std;

bool checkpath(string path, int n, bool arr[][51]){
    int x=0; int y=0;
    bool check=true;
    for(int i=0; i<n; i++){
        if(path[i] == 'R') y++;
        else x++;
        if(!arr[x][y]) check=false;
    }
    return check;
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,k;
        int ans=0;
        cin >> n>>k;
        bool arr[n][51];
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                char l;
                cin >> l;
                if(l=='.') arr[j][k] = true;
                else arr[j][k]=false;
            }
        }
        if(k>=1){
            bool check=true;
            for(int j=0; j<n; j++){
                if(!arr[0][j] || !arr[j][n-1]) check=false;
            }
            if(check) ans++;
            check=true;
            for(int j=0; j<n; j++){
                if(!arr[j][0] || !arr[n-1][j]) check=false;
            }
            if(check) ans++;
        }
        if(k>=2){
            for(int j=1; j<n-1; j++){
                string path1 = "";
                string path2 = "";
                for(int k=0; k<j; k++){
                    path1+= 'R';
                    path2+='U';
                }for(int k=0; k<n-1;k++){
                    path1+= 'U';
                    path2 += 'R';
                }for(int k=0; k<n-1-j; k++){
                    path1 += 'R';
                    path2+='U';
                }
                if(checkpath(path1, 2*n-2, arr)) ans++;
                if(checkpath(path2, 2*n-2, arr)) ans++;
            }
        }
        if(k>=3){
            for(int j=1; j<n-1; j++){
                for(int l=1; l<n-1; l++){
                string path1 = "";
                string path2 = "";
                for(int k=0; k<j; k++){
                    path1+= 'R';
                    path2+='U';
                }for(int k=0; k<l;k++){
                    path1+= 'U';
                    path2 += 'R';
                }for(int k=0; k<n-1-j; k++){
                    path1 += 'R';
                    path2+='U';
                }for(int k=0; k<n-1-l; k++){
                    path1 += 'U';
                    path2 += 'R';
                }
                if(checkpath(path1, 2*n-2, arr)) ans++;
                if(checkpath(path2, 2*n-2, arr)) ans++;
            }
            }
        }
        cout << ans<<endl;
    }
}