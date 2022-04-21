#include <iostream>
using namespace std;
struct Rect {
	int x1, y1, x2, y2;
	int area() {return (y2-y1)*(x2-x1);}
	int corners(int p1, int q1, int p2, int q2) {
		int corners=0;
		if (p1 >= x1 && p1 <= x2 && q1 >= y1 && q1 <= y2) corners+=1;
		if (p2 >= x1 && p2 <= x2 && q1 >= y1 && q1 <= y2) corners+=1;
		if (p1 >= x1 && p1 <= x2 && q2 >= y1 && q2 <= y2) corners+=1;
		if (p2 >= x1 && p2 <= x2 && q2 >= y1 && q2 <= y2) corners+=1;
		return corners;
	}
};
int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main() {
	/*freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);*/
	Rect a,b;
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	cin>>b.x1>>b.y1>>b.x2>>b.y2;
	switch (b.corners(a.x1, a.y1, a.x2, a.y2)) {
		case 2: cout<<a.area()-intersect(a,b)<<endl; break;
		case 4: cout<<0<<endl; break;
		default: cout<<a.area()<<endl; break;		
	}
}
