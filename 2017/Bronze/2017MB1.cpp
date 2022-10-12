#include <iostream>
#include <math.h>
using namespace std;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x,y;
    cin >> x>> y;
    y = y-x;
    x = 0;
    
    int su=0;
    for (int i=0; i<10000; i++){
        int k = pow(2, i);
        if(i%2 ==0){
            if(0<= y && y<=k){
                su=su+y;
                break;
            }
            else{
                su= su+2*k;
            }
        }else{
            if(-k<= y&& y <=0){
                su=su-y;
                break;
            }
            else{
                su=su+2*k;
            }
        }
    }
    cout << su;

}