#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;

using ll = long long;

struct ecow{
    ll x;
    ll y;
    bool stopped;
	bool operator<(const ecow& c) {
		return x < c.x;
	}
    int ind;
};

struct ncow{
    ll x;
    ll y;
    bool stopped;
    int ind;
};

bool compareByLength(const ecow &a, const ecow &b)
{
    return a.y < b.y;
}

bool compareByLength2(const ncow &a, const ncow &b)
{
    return a.x < b.x;
}

int main(){
    int n; 
    cin >> n;
    vector<ecow> ecows;
    vector<ncow> ncows;
    for(int i=0; i<n; i++){
        char dir; cin >> dir;
        if(dir=='E'){
            ecow c;
            cin >> c.x >> c.y; c.stopped = true;
            c.ind = i;
            ecows.push_back(c);

        }else{
            ncow c;
            cin >> c.x>>c.y; c.stopped = true;
            c.ind = i;
            ncows.push_back(c);
        }
    }
    int stopped[n];
    for(int i=0; i<n; i++) stopped[i]=0;

    sort(ecows.begin(), ecows.end(), compareByLength);
    sort(ncows.begin(), ncows.end(), compareByLength2);
    int index=0;
    for(auto ec: ecows){
        int ind2=0;
        for(auto nc: ncows){
            if(ec.stopped==true && nc.stopped==true){
                if(ec.y > nc.y && nc.x > ec.x){
                    if(ec.y - nc.y > nc.x - ec.x){
                        nc.stopped=false;
                        ncows[ind2] = nc;
                        stopped[ec.ind] += 1+stopped[nc.ind];
                    }else if(nc.x - ec.x > ec.y - nc.y){
                        ec.stopped = false;
                        ecows[index] = ec;
                        stopped[nc.ind] += 1+stopped[ec.ind];
                    }
                }
            }
            ind2++;
        }
        index++;
    }
    for(int i=0; i<n; i++) cout << stopped[i]<<endl;
}