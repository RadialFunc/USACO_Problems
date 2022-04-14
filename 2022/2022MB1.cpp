#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    string letters;
    cin >> letters;
    int k = n/2;
    vector<int> v;
    v.push_back(0);
    for(int i=1; i<k+2; i++) {
        char first = letters[n-(2*i)];
        char second = letters[n-(2*i)+1];
        if (first == 'G' && second=='G'){
            v.insert(v.begin(), 0);
        }else if (first == 'G'){
            if (v[0] % 2 ==0){
                v.insert(v.begin(), v[0]+1);
            }
        } else if (second == 'G'){
            if (v[0]%2==1){
                v.insert(v.begin(0),v[0]+1);
            }
        }
    }
    cout << v[0];
    return 0;
}