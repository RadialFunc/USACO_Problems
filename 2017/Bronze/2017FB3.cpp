#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    int arrivals[n][2];
    int arrivalsord[n][2];
    int times[n];
    for (int i=0; i<n; i++){
        int t, a;
        cin >> t>>a;
        times[i]=t;
        arrivals[i][0]=t; arrivals[i][1]=a;
    }
    sort(times, times + n);
    for(int i=0; i<n; i++){
        int val = times[i];
        for(int j=0; j<n; j++){
            if(arrivals[j][0]==val){ 
                arrivalsord[i][0] = val;
                arrivalsord[i][1]=arrivals[j][1];
            }
        }
    }
    int previous = 0;
    for(int i=0; i<n; i++){
        if(previous > arrivalsord[i][0]) previous += arrivalsord[i][1];
        else previous = arrivalsord[i][0] + arrivalsord[i][1];
    }
    cout << previous;
}