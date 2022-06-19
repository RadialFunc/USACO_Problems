#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,l;
    cin >> n>> l;
    int papers[n];
    int highesth = 0;
    int highestcit = 0;
    for(int i=0; i<n; i++){cin >> papers[i]; if(papers[i]>highestcit) highestcit = papers[i];}
    sort(papers, papers+n);
    for(int k=0; k<=highestcit; k++){
        int vs[2];
        int count=0;
        int lastl = -1;
        for(int i=0; i<n; i++){
            if(papers[i] == k-1) count++;
            if(papers[i] > k-1 && lastl ==-1) lastl = i;
        }
        vs[0] = count;
        vs[1] = n-lastl;
        if(vs[1] == n+1){
            vs[1]=0;
        }
        int neee = min(vs[0],l);
        if((neee + vs[1]) >= k){highesth = k;}

    }
    if(highestcit==0){
        cout << 1;
    }else{
    cout << highesth;}
}