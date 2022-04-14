#include <iostream>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2>> y2;
    cin >> x3>>y3>>x4>>y4;
    int a = max(x1, x2);
    int b = max(x3,x4);
    int highestx = max(a,b);
    a = min(x1, x2);
    b = min(x3,x4);
    int lowestx = min(a,b);
    a = max(y1, y2);
    b= max(y3,y4);
    int highesty = max(a,b);
    a = min(y1, y2);
    b = min(y3,y4);
    int lowesty = min(a,b);
    int side = max(highestx-lowestx, highesty-lowesty);
    cout << side*side;
    return 0;
}