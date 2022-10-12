#include <iostream>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    int start[n];
    int end[n];
    for(int i=0; i<n; i++) cin >>start[i]>>end[i];
    bool interval[1000];
    int maxs=0;
    for(int i=0;i<1000; i++) interval[i]=false;
    for(int i=0; i<n; i++){
        int total=0;
        for(int j=0; j<n; j++){
            if(i!=j){
                for(int l=start[j]; l<end[j]; l++) interval[l]=true;
            }
        }
        for(int i=0; i<1000; i++){
            if(interval[i]==true) total++;
            interval[i]=false;
        }
        if(total>maxs) maxs=total;

    }
    cout << maxs;
}