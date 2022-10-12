#include <iostream>

using namespace std;

int main(){
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
    int n,m, k;
    cin >> m >> n >> k;
    for (int i=0; i<m; i++){
        string thing= "";
        string chars;
        cin >> chars;
        for (int j=0; j<n; j++){
            for (int l=0; l<k; l++){
                thing+=chars[j];
            }
        }
        for (int p =0; p<k; p++){
            cout << thing << endl;
        }
    }
}