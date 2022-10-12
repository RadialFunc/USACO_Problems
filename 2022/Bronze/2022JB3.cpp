#include <iostream>
#include <algorithm>
using namespace std;

int feed(long long int hunger[], int num) {
    int thingy=-1;

    for (long long int i=0; i<=hunger[0]; i++){
        long long int su=0;
        bool can=true;
        long long int first = hunger[0]-i;
        su+= 2*i;
        long long int previous =i;
        for (int j=1; j<num-1; j++){
            previous = hunger[j]-previous-first;
            if (previous <0){
                can = false;
                break;
            }
            su+=2*previous;
        }
        if (hunger[num-1]-previous == first && can == true){
            if (thingy==-1){
                thingy=su;
            }
            else{
                if(su < thingy) {
                    thingy=su;
                }
            }
        }

    }
    return thingy;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        long long int hunger[num];
        for(int j=0; j<num; j++) cin >> hunger[j];
        cout << feed(hunger,num) <<endl;
    }
}