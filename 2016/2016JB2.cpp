#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    /*freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);*/
    int n;
    cin >> n;
    int hay[n];
    for(int i=0; i<n; i++) cin >> hay[i];
    sort(hay, hay+n);
    vector<int> exploded;
    int maxs=0;
    for(int i=0; i<n; i++){
        vector<int> exploded2;
        exploded.push_back(hay[i]);
        int radius=1;
        while(exploded2 != exploded){
            exploded2.clear();
            for(int j=0; j<exploded.size(); j++) exploded2.push_back(exploded[j]);
            int first = exploded[0];
            int last = exploded.back();
            exploded.clear();
            for(int j=0; j<n; j++){
                if(first-radius<=hay[j] && hay[j]<= last+radius) exploded.push_back(hay[j]);
            }
            radius++;
        }
       if(exploded.size()>maxs){
           maxs=exploded.size();
        }
        exploded.clear();
    }
    cout <<maxs;
}