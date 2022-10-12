#include <iostream>

using namespace std;

int main(){
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    pair<int, int> b,r,l;
    for(int i=0; i<10; i++){
        string chars;
        cin >> chars;
        for(int j=0; j<10; j++){
            if(chars[j] == 'B'){
                b.first=i; b.second=j;
            }else if(chars[j]== 'R'){
                r.first=i; r.second=j;
            }else if(chars[j] == 'L'){
                l.first=i; l.second=j;
            }
        }
    }
    int val = abs(b.first - l.first) + abs(b.second -l.second)-1;
    if(b.first==l.first && l.first==r.first && ((r.second < b.second && l.second < r.second) ||(r.second > b.second && l.second > r.second)  )){
        cout << val+2;
    }else if(b.second==l.second && l.second==r.second && ((r.first < b.first && l.first < r.first) ||(r.first > b.first && l.first > r.first)  )){
        cout << val+2;
    }
    else{
        cout << val;
    }

}