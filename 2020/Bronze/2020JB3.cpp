#include <iostream>
using namespace std;

int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int k, n;
    cin >> k>>n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int counter = k;
        int seconds=0;
        int speed=0;
        while(counter>0){
            if(speed<x) speed++;
            else if(speed==x){
                if(counter>x+1) speed++;
            }else{
                if(2*counter > (speed+x+1)*(speed-x)+2*speed+2) speed++; 
                else if(2*counter > (speed+x+1)*(speed-x)) speed=speed;
                else speed--;
            }
            counter -= speed;
            seconds++;
        }
        cout <<seconds<<endl;
    }
}