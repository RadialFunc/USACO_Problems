#include <iostream>
#include <set>

using namespace std;
int main(){
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    set<int> done;
    int n,m; cin >> n>>m;
    int count=0;
    for(int i=0; i<m; i++){
        char k; int x,y; cin >> k>> x>>y;
        if(done.count(x)==0 &&  done.count(y)==0) count++;
        done.insert(x); done.insert(y);
    }
    count += n-done.size();
    //cout << 1;
    //for(int i=0; i<count; i++) cout << 0;
    cout <<count;
}