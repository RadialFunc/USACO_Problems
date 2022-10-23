#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);
    map<char, map<int, int> > store;
    int n; cin >>n;
    for(int i=0; i<n; i++){
        char c; int k; cin >> c>>k;
        int m = k%7;
        if(m<0) m+=7;
        if(store[c].count(m)==1) store[c][m]+=1;
        else store[c][m]=1;
    } 
    long long ans=0;
    for(int a=0; a<7; a++){
        for(int b=0; b<7; b++){
            for(int c=0; c<7; c++){
                for(int d=0; d<7; d++){
                    for(int e=0; e<7; e++){
                        for(int f=0; f<7; f++){
                            for(int g=0; g<7; g++){
                                if((a+2*b+2*c+d)%7==0 || (e+f+b+c)%7==0 || (g+2*f)%7==0){
                                    ans += (long long)store['B'][a] * store['E'][b] * store['S'][c]*store['I'][d]*store['G'][e]*store['O'][f] *store['M'][g];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}