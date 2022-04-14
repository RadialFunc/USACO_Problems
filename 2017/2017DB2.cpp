#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    vector<int> shuffle;
    cin >> n;
    vector<int> change;
    vector<int> change2;
    for (int i=0; i<n; i++){
        int k;
        cin >>k;
        shuffle.push_back(k);
        change.push_back(i+1);
        change2.push_back(0);
    }
    for (int i=0; i<n; i++){
        int pos = shuffle[i];
        change2[pos-1] = change[i];
    }
    for (int i=0; i<n; i++){
        int pos = shuffle[i];
        change[pos-1] = change2[i];
    }
    for (int i=0; i<n; i++){
        int pos = shuffle[i];
        change2[pos-1] = change[i];
    }
    vector<int> ids;
    for (int i=0; i<n; i++){
        int id;
        cin >> id;
        ids.push_back(id);
    }

    for (int i=1; i<n+1; i++){
        for (int j=0; j<n; j++){
            if (change2[j] == i){
                cout << ids[j] <<endl;
            }
        }
    }
    
}