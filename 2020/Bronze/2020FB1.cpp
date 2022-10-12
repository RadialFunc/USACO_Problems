#include <iostream>
#include <cstdlib>
using namespace std;

struct Triangle {
	int x1, y1, x2, y2, x3, y3;
	int area() {
		return abs(x2*y1+x3*y2+x1*y3-x1*y2-x2*y3-x3*y1); 
	}
    bool parallel() {
        return ((x1==x2 || x2==x3 || x1==x3) && (y1==y2 || y2 == y3 || y1==y3));
    }
};

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    int xc[n];
    int yc[n];
    int area=0;
    for(int i=0; i<n; i++) cin >> xc[i] >> yc[i];
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                Triangle t;
                t.x1 = xc[i]; t.x2 = xc[j]; t.x3 = xc[k]; t.y1=yc[i]; t.y2 = yc[j]; t.y3=yc[k];
                if (t.parallel()){
                    if(t.area()> area) area = t.area();
                }
            }
        }
    }
    cout << area;
}