#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<int> notes;
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        notes.push_back(k);
    }
    int k;
    cin >> k;
    vector<int> ruminant;
    for (int i=0; i<k; i++){
        int l;
        cin >> l;
        ruminant.push_back(l);
    }
    int total=0;
    sort(ruminant.begin(), ruminant.end());
    for (int i=0; i<n-k+1; i++){
        vector<int> letters;
        for (int j=0; j<k; j++){
            letters.push_back(notes[j+i]);
        }
        sort(letters.begin(), letters.end());
        int difference  = letters[0]-ruminant[0];
        bool works =true;
        for (int b=0; b<k; b++){
            if(!(difference+ruminant[b]==letters[b])){
                works=false;
                break;
            }
        }
        if (works ==true){
            total+=1;
        }

    }
    cout << total;
}