#include <bits/stdc++.h>
using namespace std;

float dcplaces(float x){
    return round( x * 1000.0 ) / 1000.0;
}
float a[100000];

bool possible(float change, int s){
    float b[s];
    for(int i=0; i<s; i++) b[i] = a[i]-change;
    float total =0; for(int i=0; i<s; i++) total+= a[i];
    float best = b[1]; float curr = 0.0;
    for(int i=1; i<s-1; i++){
        curr += b[i];
        if(curr<0) curr=0;
        if(curr>best) best=curr;
    }
    return best>= total - change*s;
}

int main(){
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    int n; cin >> n;
    float total=0;
    for(int i=0; i<n; i++){cin >> a[i]; total+=a[i];}
    float l =1.0; float h = 10000.0;

    while(dcplaces(l)!= dcplaces(h)){
        float avg = (l+h)/2;
        if(possible(avg, n)) h=avg;
        else l=avg;
    }
    int before = round(l*1000.0);
    string ans = to_string(before);
    for(int k=0; k<ans.size(); k++){
        cout << ans[k];
        if(k == ans.size()-4) cout <<'.';
    }
}