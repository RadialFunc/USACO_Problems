#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n;
    cin >> n;
    map<int, int> xtoy;
    map<int, int> ytox;
    multiset<int> xcoord;
    multiset<int> ycoord;
    set<int> dxcoord;
    set<int> dycoord;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x>>y;
        xtoy[x]=y;
        ytox[y]=x;
        xcoord.insert(x);
        ycoord.insert(y);
        dxcoord.insert(x);
        dycoord.insert(y);
    }
    int highestx = *--dxcoord.end();
    int lowestx = *dxcoord.begin();
    int highesty = *--dycoord.end();
    int lowesty = *dycoord.begin();
    int currentarea = (highestx-lowestx)*(highesty-lowesty);
    if(currentarea==0){
        cout << 0;
        return 0;
    }
    if(xcoord.count(highestx)==1){
        dxcoord.erase(highestx);
        dycoord.erase(xtoy[highestx]);
        currentarea = min(currentarea, (*--dxcoord.end() - *dxcoord.begin())*(*--dycoord.end() - *dycoord.begin()));
        dxcoord.insert(highestx);
        dycoord.insert(xtoy[highestx]);
    }
    if(xcoord.count(lowestx)==1){
        dxcoord.erase(lowestx);
        dycoord.erase(xtoy[lowestx]);
        currentarea = min(currentarea, (*--dxcoord.end() - *dxcoord.begin())*(*--dycoord.end() - *dycoord.begin()));
        dxcoord.insert(lowestx);
        dycoord.insert(xtoy[lowestx]);
    }
    if(ycoord.count(lowesty)==1){
        dycoord.erase(lowesty);
        dxcoord.erase(ytox[lowesty]);
        currentarea = min(currentarea, (*--dxcoord.end() - *dxcoord.begin())*(*--dycoord.end() - *dycoord.begin()));
        dycoord.insert(lowesty);
        dxcoord.insert(ytox[lowesty]);
    }
    if(ycoord.count(highesty)==1){
        dycoord.erase(highesty);
        dxcoord.erase(ytox[highesty]);
        currentarea = min(currentarea, (*--dxcoord.end() - *dxcoord.begin())*(*--dycoord.end() - *dycoord.begin()));
        dycoord.insert(highesty);
        dxcoord.insert(ytox[highesty]);
    }
    cout << currentarea;
}   