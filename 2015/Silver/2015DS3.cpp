#include <iostream>
using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n,q;
    cin >> n>>q;
    int a[n+1], b[n+1], c[n+1];
    a[0]=0; b[0]=0; c[0]=0;
    for(int i=0; i<n; i++){
        int bree;
        cin >> bree;
        a[i+1] =a[i]; b[i+1]=b[i]; c[i+1]=c[i];
        if(bree==1) a[i+1]++;
        else if(bree==2) b[i+1]++;
        else c[i+1]++;
    }
    for(int i=0; i<q; i++){
        int m, k;
        cin >> m>>k;
        cout << a[k] - a[m-1] << " " << b[k] - b[m-1] << " "<<c[k] - c[m-1] << endl;
    }
}