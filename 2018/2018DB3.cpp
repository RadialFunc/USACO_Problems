#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> pails1;
    vector<int> pails2;
    for(int i=0; i<10; i++){
        int pail;
        cin >> pail;
        pails1.push_back(pail);
    }
    for(int i=0; i<10; i++){
        int pail;
        cin >> pail;
        pails2.push_back(pail);
    }
    vector<int> possible;
    for(int i=0; i<10; i++){
        for(int j=0; j<11; j++){
            vector<int> newpails1;
            vector<int> newpails2;
            if(j!=10){

                for(int l=0; l<10; l++){
                    if (l!=i) newpails1.push_back(pails1[l]);
                }
                newpails1.push_back(pails2[j]);
                for(int l=0; l<10; l++){
                    if(l!= j) newpails2.push_back(pails2[l]);
                }
                newpails2.push_back(pails1[i]);
            }else{
                for(int l=0; l<10; l++) newpails1.push_back(pails1[l]);
                for(int l=0; l<10; l++) newpails2.push_back(pails2[l]);
            }
            for(int l=0; l<10; l++){
                for(int p=0; p<11; p++){
                    if(j==10 && p==10) possible.push_back(0);
                    else if(j==10) possible.push_back(newpails2[p]-newpails1[l]);
                    else if(p==10) possible.push_back(pails2[j] - pails1[i]);
                    else possible.push_back(pails2[j]-pails1[i]+newpails2[p]-newpails1[l]);
                }
            }
        }
    }
    int count=0;
    sort(possible.begin(), possible.end());
    for(unsigned int i=0; i<possible.size(); i++){
        while(i<possible.size()-1 && possible[i]==possible[i+1]){
            i++;
        }
        count++;
    }
    cout << count;
}