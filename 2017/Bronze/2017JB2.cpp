#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int> > games;

int wins(int hoof, int scissors, int paper, int n){
    int wins=0;
    for (int i=0; i<n; i++){
        if(games[i][0] == hoof && games[i][1] == scissors) wins++;
        if(games[i][0] == scissors && games[i][1] == paper) wins++;
        if(games[i][0] == paper && games[i][1] == hoof) wins++;
    }
    return wins;
}
int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> game;
        int a,b;
        cin >> a>>b;
        game.push_back(a);
        game.push_back(b);
        games.push_back(game);
    }
    int w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11;
    w1 = wins(1,2,3,n);
    w2 = wins(1,3,2,n);
    w3 = wins(2,1,3,n);
    w4 = wins(2,3,1,n);
    w5 = wins(3,2,1,n);
    w6 = wins(3,1,2,n);
    w7 = max(w1, w2);
    w8 = max(w3,w4);
    w9 = max(w5,w6);
    w10 = max(w7,w8);
    w11 = max(w10, w9);
    cout << w11;
}