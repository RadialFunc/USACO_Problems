#include <iostream>

using namespace std;

int main(){
	//freopen("ctiming.in", "r", stdin);
	//freopen("ctiming.out", "w", stdout);
    int date, hour, minute;
    cin >> date >> hour >> minute;
    int mins= (date-11)*1440+(hour-11)*60+(minute-11);
    if (mins <0){
        cout << -1;
    }
    else{
        cout << mins;
    }
    return 0;
}