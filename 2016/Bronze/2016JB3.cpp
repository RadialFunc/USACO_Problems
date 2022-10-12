#include <iostream>
#include <map>
#include <utility> 
using namespace std;

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n;
    cin >> n;
    int t=0;   
    int count=10000000;
    pair<int, int> coordinates;
    map<pair<int, int>, int> visited;
    coordinates.first=0;
    coordinates.second=0;
    for(int i=0; i<n; i++){
        char direction; int amt;
        cin >> direction >> amt;
        if(direction == 'N'){
            for(int j=0; j<amt; j++){
                t++;
                coordinates.second++;
                if(visited.count(coordinates)==1){
                    count = min(count, t-visited[coordinates]);
                }
                visited[coordinates]=t;
            }
        }else if(direction == 'S'){
            for(int j=0; j<amt; j++){
                t++;
                coordinates.second--;
                if(visited.count(coordinates)==1){
                    count = min(count, t-visited[coordinates]);
                }
                visited[coordinates]=t;
            }

        }else if(direction == 'W'){
            for(int j=0; j<amt; j++){
                t++;
                coordinates.first--;
                if(visited.count(coordinates)==1){
                    count = min(count, t-visited[coordinates]);
                }
                visited[coordinates]=t;
            }

        }else{
            for(int j=0; j<amt; j++){
                t++;
                coordinates.first++;
                if(visited.count(coordinates)==1){
                    count = min(count, t-visited[coordinates]);
                }
                visited[coordinates]=t;
            }
        }
    }
    if(count==10000000){
        cout << -1;
    }else{    
        cout << count;
    }
}