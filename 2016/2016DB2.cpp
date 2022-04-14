#include <iostream>
#include <algorithm>
using namespace std;

int count_underscores(string s, char h) {
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == h) count++;

  return count;
}

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin >> n;
    int let[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0 , 0 ,0,0,0,0,0};
    for (int i=0; i<n; i++){
        string w1, w2;
        cin >> w1 >> w2;
        for (int j=97; j<123; j++){
            char letter = j;
            int k = max(count_underscores(w1, letter), count_underscores(w2, letter));
            int l = j-97;
            let[l] += k;
        }
    }   
    for (int i=0; i<26; i++){
        cout << let[i] <<endl;
    }
}