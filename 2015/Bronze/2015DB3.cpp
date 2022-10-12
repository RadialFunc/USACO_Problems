#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int n,m,d,s;
    cin >> n>> m>>d>>s;
    int drinks[d][3];
    for(int i=0; i<d; i++){
        cin >> drinks[i][0]>>drinks[i][1]>>drinks[i][2];
    }
    int sicks[s][2];
    for(int i=0; i<s; i++){
        cin >> sicks[i][0]>>sicks[i][1];
    }
    vector<vector<int> > all;
    for(int i=0; i<s; i++){
        vector<int> single;
        for(int j=0; j<d; j++){
            if (drinks[j][0] == sicks[i][0] && drinks[j][2]<sicks[i][1]) single.push_back(drinks[j][1]); 
        }
        all.push_back(single);
    }
    vector<int> possible;
    int total=0;
    for(int i=1; i<m+1; i++){
        bool check=true;
        for(int j=0; j<s;j++){
            bool check2=false;
            vector<int> curr = all[j];
            for(unsigned int l=0; l<curr.size(); l++){
                if(curr[l]==i) check2=true;
            }
            if(check2==false) check=false;
        }
        if(check) possible.push_back(i); 
    }
    int maxs=0;
    for(unsigned int i=0; i<possible.size(); i++){
        int k = possible[i];
        int p=0;
        vector<int> peopledrank;
        for(int j=0; j<d; j++){
            if(drinks[j][1]==k) peopledrank.push_back(drinks[j][0]); 
        }
        sort(peopledrank.begin(), peopledrank.end());
        for(unsigned int j=0; j<peopledrank.size(); j++){
            while(j<s-1 && peopledrank[j]==peopledrank[j+1]) j++;
            p++;
        }
        if(p>maxs) maxs=p;
    }
    cout << maxs;
}