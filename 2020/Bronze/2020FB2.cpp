#include <iostream>

using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;

    int count=0;
    string desired, wanted;
    cin >> wanted >> desired;
    bool current = true;
    for(int i=0; i<n; i++){
        if(desired[i] == wanted[i]){
            current = true;
        }else{
            if(current==true){
                count++;
            }
            current=false;
        }
    }
    cout << count;
}