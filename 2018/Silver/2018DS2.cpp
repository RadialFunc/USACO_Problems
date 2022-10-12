#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n; cin >> n;
    pair<int, pair<int, int> > cows[n];
    map<int, pair<int, int> > prior;
    for(int i=0; i<n; i++){
        cin >> cows[i].first>>cows[i].second.second;
        cows[i].second.first = n-i-1;
        prior[n-i-1].first = cows[i].first; prior[n-1-i].second = cows[i].second.second;
    }
    sort(cows, cows+n);
    int count = 0;
    set<int> waiting;
    waiting.insert(cows[0].second.first);
    int start = cows[0].first;
    int ma = 0;
    while(count <n){
        if(waiting.size()==0){waiting.insert(cows[count].second.first); start = cows[count].first;}
        int current = *waiting.rbegin();
        waiting.erase(current);
        count++;
        ma = max(ma, start-prior[current].first);
        //cout << start << " "<<prior[current].first << " "<<current << endl;
        for(int i=count; i<n; i++){
            if(cows[i].first > start+prior[current].second) break;
            else if(cows[i].first >= start && cows[i].first <= start+prior[current].second) waiting.insert(cows[i].second.first);
        }
        start += prior[current].second;
    }   
    cout << ma;
}