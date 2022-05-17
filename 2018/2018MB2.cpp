#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m,k;
    cin >> n>>m>>k;
    int hierarchy[m];
    map<int, int> positions;
    bool check=false;
    for(int i=0; i<m;i++){
        cin >> hierarchy[i];
        if(hierarchy[i]==1) check=true;
    }
    for(int i=0; i<k; i++){
        int ci, pi;
        cin >> ci >> pi;
        positions[ci]=pi;
    }
    if(positions.count(1) == 1){cout << positions[1]; return 0;}

    if(check){
        
    }
}