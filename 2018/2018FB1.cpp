#include <iostream>
#include <math.h>
using namespace std;

int main(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a,b,x,y;
    cin >> a>>b>>x>>y;
    int first = abs(a-b);
    int second = abs(a-x)+abs(b-y);
    int third = abs(a-y) + abs(b-x);
    int fourth = min(first,second);
    cout << min(fourth, third);
}