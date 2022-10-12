#include <iostream>
#include <utility>
using namespace std;

string shoelace(pair<int, int> coords[], int len){
    int area=0;
    for(int i=0; i<len; i++){
        area += coords[i].second*coords[i+1].first - coords[i].first*coords[i+1].second;
    }
    if(area>0) return "CW";
    else return "CCW";
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string dir;
        cin >> dir;
        pair<int, int> coords[dir.length()+1];
        pair<int, int> loc; loc.first=0; loc.second=0;
        coords[0] = loc;
        for(int i=0; i<dir.length(); i++){
            char move = dir[i];
            if(move == 'N') loc.second++;
            else if(move == 'E') loc.first++;
            else if(move == 'W') loc.first--;
            else loc.second--;
            coords[i+1] = loc;
        }
        cout << shoelace(coords, dir.length())<<endl;;
    }
}