#include <iostream>
using namespace std;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    int logs[n];
    for(int i=0; i<n; i++) cin >> logs[i];
    logs[0]=0;
    for(int i=0; i<n; i++){
        if(logs[i]>0){
            int k =logs[i];
            for(int j=0; j<k; j++){
                logs[j+i-k] = j;
            }
        }
    }
    int max =0;
    int min =0;
    for(int i=0; i<n; i++){
        //cout << logs[i];
        if(logs[i]==0) {
            max++;
            min++;
        }else if (logs[i]==-1) max++;
    }
    cout << min<<" "<<max;
}