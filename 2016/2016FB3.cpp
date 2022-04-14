#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > cows;

int calculateleast(int a, int b, int n){
    int x=0; int y=0; int z=0; int w=0;
    for(int i=0; i<n; i++){
        if(cows[i][0] > a && cows[i][1]>b) x++;
        if(cows[i][0] > a && cows[i][1]<b) y++;
        if(cows[i][0] < a && cows[i][1]>b) z++;
        if(cows[i][0] < a && cows[i][1]<b) w++;
    }
    int p,q, r;
    return max(max(x,y), max(z,w));
}

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n;
    cin >> n;
    int leastx=1000000;
    int leasty = 1000000;
    int highestx = 0;
    int highesty =0; 
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x>>y;
        vector<int> cow;
        cow.push_back(x); cow.push_back(y); cows.push_back(cow);
        if (x<leastx) leastx = x;
        if(x>highestx) highestx =x;
        if (y<leasty) leasty = y;
        if(y>highesty) highesty =y; 
    }
    int least=n;
    for(int a=leastx-1; a<=highestx+1; a+=2){
        for(int b=leasty-1; b<=highesty+1; b+=2){
            int val =calculateleast(a,b, n);
            if(val<least) least=val;
        }
    }
    cout << least;
}