#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int comphindex(vector<int> papers, int n){
    for(int k=0; k<n; k++){
        if(k+1>= papers[k]) return papers[k];
    }
    return 0;
}

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> papers;
    multiset<int> papers2;
    for(int i=0; i<n; i++){int k; cin >> k; papers.push_back(k); papers2.insert(k);}
    sort(papers.begin(), papers.end(), greater<int>());
    int h = comphindex(papers, n); 
    int amt = papers2.count(h);
    for(int i=0; i<min(l,amt); i++) papers.push_back(h+1);

    sort(papers.begin(), papers.end(), greater<int>());
    cout << comphindex(papers, papers.size());
}