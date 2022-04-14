#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    int least =0;
    vector<int> travel;
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        travel.push_back(k);
    }
    
    for (int i=0; i<n; i++){
        vector<int> v;
        int sum=0;
        for (int j=i; j<n; j++){
            v.push_back(travel[j]);
        }
        for(int j=0; j<i; j++){
            v.push_back(travel[j]);
        }

        for(int j=0; j<n; j++){
            sum+= j*v[j];
        }
        if (sum<least || least==0){ 
            least = sum;
        }
    }
    cout << least;
}