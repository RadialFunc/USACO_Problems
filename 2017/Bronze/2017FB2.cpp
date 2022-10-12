#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > positions;

bool cross(int a, int b){
    if(positions[a][0] < positions[b][0]){
        if(positions[a][1]>positions[b][0] && positions[a][1]<positions[b][1]){
            return true;
        }else{
            return false;
        }
    }else{
        if(positions[b][1]>positions[a][0] && positions[b][1]<positions[a][1]){
            return true;
        }else{
            return false;     
    }
}
}

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string chars;
    cin >> chars;
    int cros=0;
    for(int j=65; j<91; j++){
        vector<int> lett;
        for(int i=0; i<52; i++){
            char cow = chars[i];
            if(int(cow) == j) lett.push_back(i);
        }
        positions.push_back(lett);
    }
    for(int i=0; i<25; i++){
        for(int j=i+1; j<26; j++){
            if(cross(i,j)) cros++;
        }
    }
    cout << cros;
}