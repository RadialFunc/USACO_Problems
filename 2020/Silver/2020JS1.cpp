#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n,k; cin >> n>>k;
    int arr[n];
    int highest=0;
    for(int i=0; i<n; i++){cin >> arr[i]; highest = max(highest, arr[i]);}
    int ans=0;
    for(int i=1; i<= highest; i++){
        int count =0; 
        int remainders[n];
        for(int j=0; j<n; j++){
            count+= floor(arr[j]/i);
            remainders[j] = arr[j]%i;
        }
        sort(remainders, remainders+n, greater<int>());
        if(count >= k){ans = max(ans, k/2*i);}
        else if(k/2 <= count){
            int val = (count-k/2)*i;
            int counter = 0;
            while(counter<(k/2-(count-k/2)) && counter <n){
                val += remainders[counter];
                counter++;
            }
            ans = max(ans, val);
        }else{
            int counter = k/2-count;
            int val=0;
            while(counter < n && counter-(k/2-count) < k/2){val+= remainders[counter]; counter++;}
            ans = max(ans, val);
        }
    }
    cout << ans;
}