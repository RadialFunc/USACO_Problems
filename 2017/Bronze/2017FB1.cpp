#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int> > crossings;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a>>b;
        vector<int> g;
        g.push_back(a);
        g.push_back(b);
        crossings.push_back(g);
    }
    int total=0;
    for (int i=1; i<11; i++){
        int crossing=0;
        vector<int> v;
        int len=0;
        for(int j=0; j<n; j++){
            if (crossings[j][0] == i){
                v.push_back(crossings[j][1]);
                len++;
            }
        }
        for(int j=1; j<len; j++){
            if (v[j] != v[j-1]){
                crossing++;
            }
        }
        total+= crossing;
    }
    cout << total;
}