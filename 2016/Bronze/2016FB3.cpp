#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > cows;
vector <int> x_cors, y_cors;

int calculateleast(int a, int b, int n){
    int x=0; int y=0; int z=0; int w=0;
    for(int i=0; i<n; i++){
        if(cows[i].first > a && cows[i].second>b) x++;
        if(cows[i].first > a && cows[i].second<b) y++;
        if(cows[i].first < a && cows[i].second>b) z++;
        if(cows[i].first < a && cows[i].second<b) w++;
    }
    int p,q, r;
    return max(max(x,y), max(z,w));
}

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n,k;
    cin >> n;
    
    int least = n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x>>y;
		x_cors.push_back(x - 1);
		y_cors.push_back(y - 1);
		pair <int, int> coordinates (x, y);
		cows.push_back(coordinates);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
			int a = x_cors[i];
            int b = y_cors[j];
            least = min(least, calculateleast(a,b,n));
        }
    }
    cout << least;
}