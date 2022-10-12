#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout); 
    ll n; cin >> n;
    if(n%8==0) cout << 15*n/8 -1;
    else if(n%8==1) cout << 15*(n-1)/8 + 1;
    else if(n%8 ==2) cout << 15*(n-2)/8 +2;
    else if(n%8==3) cout << 15*(n-3)/8 +4;
    else if(n%8==4) cout << 15*(n-4)/8 + 7;
    else if(n%8==5) cout << 15*(n-5)/8 + 8;
    else if(n%8==6) cout << 15*(n-6)/8 + 11;
    else if(n%8==7) cout << 15*(n-7)/8 + 13;
}