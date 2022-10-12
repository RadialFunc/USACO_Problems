#include <iostream>
#include <utility>
#include <map>
#include <functional>
using namespace std;


int main(){
    int n;
    cin >> n;
    map<pair<int, int>, int> counts;
    int comfortable =0;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x>>y;
        pair<int, int> nor, noru, nord, norr, norl;
        nor.first = x; nor.second=y;
        noru.first = x+1; noru.second = y;
        nord.first = x-1; nord.second=y;
        norr.first = x; norr.second=y+1;
        norl.first = x; norl.second=y-1;
        int yes=0;
        if(counts.count(noru)==1){
            yes++;
            counts[noru] = counts[noru]+1;
            if(counts[noru]==3) comfortable++;
            else if(counts[noru]==4) comfortable--;
        }
        if(counts.count(norl)==1){
            yes++;
            counts[norl]++;
            if(counts[norl]==3) comfortable++;
            else if(counts[norl]==4) comfortable--;
        }
        if(counts.count(nord)==1){
            yes++;
            counts[nord]++;
            if(counts[nord]==3) comfortable++;
            else if(counts[nord]==4) comfortable--;
        }
        if(counts.count(norr)==1){
            yes++;
            counts[norr]++;
            if(counts[norr]==3) comfortable++;
            else if(counts[norr]==4) comfortable--;
        }
        counts[nor] = yes;
        if(yes==3) comfortable++;
        cout << comfortable <<endl;
    }
}