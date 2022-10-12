#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
using namespace std;

class cow {
    public:
        char dir;
        int x;
        int y;
};

class inter {
    public:
        int time;
        pair<int, int> pont;
        bool visited;
        int cow;
};

struct less_than_key
{
    inline bool operator() (const inter& struct1, const inter& struct2)
    {
        return (struct1.time < struct2.time);
    }
};

int main(){
    int n;
    cin >> n;
    cow cows[n];
    for (int i=0; i<n; i++){
        cin >> cows[i].dir>>cows[i].x>> cows[i].y;
    }
    set<pair<int, int> > visited;
    vector<inter> inters;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(cows[i].dir != cows[j].dir){
                if(cows[i].dir=='E' && cows[i].x <= cows[j].x && cows[i].y >= cows[j].y){
                    if(cows[j].x-cows[i].x != cows[i].y-cows[j].y){
                    inter c1, c2;
                    c1.time = cows[j].x-cows[i].x; c1.visited=false; c1.cow = i; c1.pont.first=cows[j].x; c1.pont.second = cows[i].y;
                    c2.time = cows[i].y-cows[j].y; c2.visited=false; c2.cow = j; c2.pont.first=cows[j].x; c1.pont.second = cows[i].y;
                    inters.push_back(c1); inters.push_back(c2);}
                }else if(cows[j].dir=='E' && cows[j].x <= cows[i].x && cows[j].y >= cows[i].y){
                    if(cows[i].x-cows[j].x != cows[j].y-cows[i].y){
                    inter c1, c2;
                    c1.time = cows[j].y-cows[i].y; c1.visited=false; c1.cow = i; c1.pont.first=cows[i].x; c1.pont.second = cows[j].y;
                    c2.time = cows[i].x-cows[j].x; c2.visited=false; c2.cow = j; c1.pont.first=cows[i].x; c1.pont.second = cows[j].y;
                    inters.push_back(c1); inters.push_back(c2);}
                }
                }
            }
        }
    map<int, int> ans;
    sort(inters.begin(), inters.end(), less_than_key());
    for(int i=0; i<inters.size(); i++){
        int cowq = inters[i].cow;
        if(ans.count(cowq)==0){
            pair<int, int> current = inters[i].pont;
            if(visited.count(current)==1) ans[cowq] = inters[i].time;
            else visited.insert(current);
        }
    }
    for(int i=0; i<n; i++){
        if(ans.count(i)==0){
            cout << "Infinity" << endl;
        }else{
            cout << ans[i] << endl;
        }
    }
}
