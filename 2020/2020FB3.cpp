#include <iostream>
#include <map>
using namespace std;

int change(int ind, int a1, int a2, int b1, int b2){
    if(a1<= ind && a2 >= ind) ind = (a2+a1)-ind;
    if(b1<= ind && b2 >= ind) ind = (b2+b1)-ind;
    return ind;
}

int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k, a1, a2, b1, b2;
    cin >> n>>k>>a1>>a2>>b1>>b2;
    map<int, int> ggg; 
    for(int i=0; i<n; i++){
        if(k<=100){
            int ind = i+1;
            for(int j=0; j<k; j++) ind = change(ind, a1, a2, b1, b2);
            ggg[i+1] = ind;
        }else{
            int ind = i+1;
            map<int, int> valafterk;
            int rep1, rep2, repv;
            for(int j=0; j<=100;j++){
                if(valafterk.count(ind)==1){
                    rep1 = valafterk[ind]; rep2 = j; repv = ind;
                    break;
                } 
                valafterk[ind] = j;
                ind = change(ind, a1, a2, b1, b2);
            }
            int remaining = (k-rep1) % (rep2-rep1);
            for(int j=0; j<remaining; j++){
                repv = change(repv, a1, a2, b1, b2);
            }
            ggg[i+1] = repv;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(ggg[j] == i) cout << j << endl;
        }
    }
}