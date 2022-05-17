#include <iostream>
using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    int order[n];
    int counter=n-1;
    for(int i=0; i<n; i++){
        cin >> order[i];
    }
    for(int i=n-2; i>=0; i--){
        if(order[i]<order[i+1]) counter=i;
        else break;
    }
    cout << counter;
}