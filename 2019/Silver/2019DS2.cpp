#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    int n;
    int l;
    cin >> n>>l;
    pair<int,int> times[n];
    pair<int, pair<int, int> > cows[n];
    int total = 0;
    for(int i=0; i<n; i++){
        cin >> cows[i].second.first>>cows[i].first>>cows[i].second.second;
        total+= cows[i].second.first;
        pair<int, int> co;
        co.second = cows[i].second.second;
        if(co.second==1){co.first = l-cows[i].first; times[i]=co;}
        else{co.first = cows[i].first; times[i]=co;}
    }
    sort(cows, cows+n);
    sort(times, times+n);
    int forward =0; int back=n-1;
    int weight=0;
    int index =-1;
    while(2*weight < total){
        index++;
        if(times[index].second ==-1){
            weight+=cows[forward].second.first;
            forward++;
        }else{
            weight+= cows[back].second.first;
            back--;
        }
    }
    int t=times[index].first;
    queue<int> poss;
    int ans=0;
    for(int i=0; i<n; i++){
        if(cows[i].second.second==-1){
            while(poss.size() && poss.front()+2*t < cows[i].first) poss.pop();
            ans+= poss.size();
        }else{
            poss.push(cows[i].first);
        }
    }
    cout << ans;
}