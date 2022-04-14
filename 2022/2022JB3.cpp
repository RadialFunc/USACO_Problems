#include <iostream>
#include <algorithm>
using namespace std;

int feed(int hunger[], int num) {
    int thingy=0;

    for (int i=0; i<hunger[0]; i++){
        int su=0;
        bool can=true;
        int first = hunger[0]-i;
        su+= 2*i;
        int previous =i;
        for (int j=1; j<num-1; j++){
            previous = hunger[j]-previous-first;
            if (previous <0){
                can = false;
                break;
            }
            su+=2*previous;
        }
        if (hunger[num-1]-previous == first && can == true){
            if (thingy==0){
                thingy=su;
            }
            else{
                if(su < thingy) {
                    thingy=su;
                }
            }
        }

        }

    if(thingy==0){
    return -1;
    }
    return thingy;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        int hunger[num];
        for(int j=0; j<num; j++) cin >> hunger[j];
        cout <<endl<< feed(hunger,num) ;
    }
}