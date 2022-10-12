#include <iostream>
#include <vector>
using namespace std;

bool duplicate(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i] == arr[j] && i != j){
                return false;
            }
        }
    }
    return true;
}

int main(){
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n;
    cin >> n;
    int record[n-1];
    for(int i=0; i< n-1; i++){
        cin >> record[i];
    }
    for (int i=1; i<n+1; i++){
        int arr[n];
        arr[0]= i;
        bool poss= true;
        for(int j=1; j<n; j++){
            int diff = record[j-1]- arr[j-1];
            if (diff<=0 || diff>n){
                poss = false;
                break;
            }else{
                arr[j] = diff;
            }
        }
        if (poss==true){
            if (duplicate(arr, n)){
                for (int j=0; j<n; j++){
                    if (j==n-1){
                        cout << arr[j];
                    }else{
                    cout << arr[j] << " ";}
                }
                i = n;
            }
        }
    }
}