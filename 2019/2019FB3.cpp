#include <iostream>
using namespace std;

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n][3];
    for(int i=0; i<n; i++){
        string t;
        cin >> t>>arr[i][1]>>arr[i][2];
        if(t=="on") arr[i][0]=1;
        else if(t=="off") arr[i][0]=2;
        else arr[i][0]=0;
    }
    int lstvalid=1001;
    int maxvalid=0;

    for(int i=0; i<1001; i++){
        bool check=true;
        int least=i;
        int most=i;
        for(int j=0; j<n; j++){
            if(arr[j][0]==0){
                if(least < arr[j][1] && most< arr[j][1]) check=false;
                if(most > arr[j][2] && least > arr[j][2]) check=false;
            }else if(arr[j][0]==1){
                least += arr[j][1];
                most += arr[j][2];
            }else{
                least -= arr[j][2]; most -= arr[j][1];
            }
        }
        if(check){lstvalid = min(i, lstvalid); maxvalid = max(i, maxvalid);}
    }
    int lstval=1001;
    int maxval=0;
    for(int i=0; i<1001; i++){
        bool check=true;
        int least=i;
        int most=i;
        for(int j=0; j<n; j++){
            if(arr[n-1-j][0]==0){
                if(least < arr[n-1-j][1] && most< arr[n-1-j][1]) check=false;
                if(most > arr[n-1-j][2] && least > arr[n-1-j][2]) check=false;
            }else if(arr[n-1-j][0]==2){
                least += arr[n-1-j][1];
                most += arr[n-1-j][2];
            }else{
                least -= arr[n-1-j][2]; most -= arr[n-1-j][1];
            }
        }
        if(check){lstval = min(i, lstval); maxval = max(i, maxval);}
    }
    cout << lstvalid<< " "<<maxvalid<< endl << lstval << " "<<maxval;
}
