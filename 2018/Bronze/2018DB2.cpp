#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    vector<vector<int> > milk;
    int n;
    cin >> n;
    int greatest=0;
    for (int i=0; i<n; i++){
        vector<int> cow;
        int s;
        int t;
        int b;
        cin >> s>> t>> b;
        if(t> greatest) greatest=t;
        cow.push_back(s);
        cow.push_back(t);
        cow.push_back(b);
        milk.push_back(cow);
    }    
    int great=0;
    for (int i=1; i<= greatest; i++){
        int buckets =0;
        for (int j=0; j<n; j++){
            if(i>=milk[j][0] && i<=milk[j][1]){
                buckets+=milk[j][2];
            }
        }
        if (buckets> great) great=buckets;
    }
    cout << great;
}