#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
    int n,m;
    cin >> n>>m;
    vector<vector<int> > segments;
    int yet = 0;
    for(int i=0; i<n; i++){
        int distance, speed;
        cin >> distance >> speed;
        vector<int> arr;
        arr.push_back(yet);
        arr.push_back(yet+distance);
        arr.push_back(speed);
        segments.push_back(arr);
        yet+=distance;
    }
    int exceeded=0;
    int yet2=0;
    for (int i=0; i<m; i++){
        int distance, speed;
        cin >> distance >> speed;
        for (int j=yet2; j< yet2+distance; j++){
            for(int l=0; l<n; l++){
                if (segments[l][0] <= j && j<segments[l][1]){
                    int newspeed = speed-segments[l][2];
                    if (newspeed > exceeded){
                        exceeded = newspeed;
                    }
                }
            }
        }
        yet2 += distance;
    }
    cout << exceeded;
}