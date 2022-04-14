#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int convert(string cow){
    if(cow=="Mildred") return 0;
    if (cow=="Bessie") return 1;
    if (cow=="Elsie") return 2;
}

vector<int> winner(int arr[]){
    int max =0;
    vector<int> v;
    for(int i=0; i<3; i++){
        if (arr[i]> max) max = arr[i];
    }
    for(int i=0; i<3; i++){
        if(arr[i] == max) v.push_back(i);
    }
    return v;
}

int main(){
    freopen("measurement.in","r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    vector<vector<int> > schedule;
    for(int i=0; i<n; i++){
        int day, change;
        string cow;
        cin >> day >> cow>> change;
        int cown = convert(cow);
        vector<int> produce;
        produce.push_back(day);
        produce.push_back(cown);
        produce.push_back(change);
        schedule.push_back(produce);
        arr[i] = day;
    }
    sort(arr, arr + n);
    vector<vector<int> > sched;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i] == schedule[j][0]){
                sched.push_back(schedule[j]);
            }
        }
    }
    int cows[] = {7,7,7};
    vector<vector<int> > iwnners;
    vector<int> all;
    all.push_back(0);
    all.push_back(1);
    all.push_back(2);
    iwnners.push_back(all);
    int tot=0;
    iwnners.push_back(all);
    for(int i=0; i<n; i++){
        cows[sched[i][1]] += sched[i][2];
        if(iwnners[iwnners.size()-1] == winner(cows)){
            int sus=0;
        }else{
            tot+=1;
            iwnners.push_back(winner(cows));
        }
    }
    cout << tot;

}