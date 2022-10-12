#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, t; cin >> s>>t;
    string ans;
    for(int i=0; i<s.size(); i++){
        ans+= s[i];
        if(ans.size() >= t.size()){
            if(ans.substr(ans.size()-t.size()) == t){
                ans.erase(ans.size() - t.size(), t.size());
            }
        }
    }
    cout << ans;
}