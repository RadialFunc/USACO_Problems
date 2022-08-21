#include <iostream>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    int val = max(b,d) - min(a,c);
    if(b<c){val -= c-b;}
    else if(d<a){val -= a-d;}
    cout << val;
}