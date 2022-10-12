#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stalls;

int more(int val, int n){
    int total=0;
    for(int i=0; i<n; i++){
        if (stalls[i]>= val) total++;
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    long long int final =1;
    vector<long long int> cows;
    for(int i=0; i<n; i++){
        long long int k; 
        cin >>k; 
        cows.push_back(k);
    }
    for(int i=0; i<n; i++){
        long long int k; 
        cin >>k; 
        stalls.push_back(k);
    }
    sort(cows.begin(), cows.end(), greater<int>());
    for(int i=0; i<n; i++){
        long long int val = cows[i];
        int poss = max(more(val, n),0);
        final *= poss-i;
    }
    cout << final;
}