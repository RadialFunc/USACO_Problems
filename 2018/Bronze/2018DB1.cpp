#include <iostream>
using namespace std;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int c1, w1, c2, w2, c3, w3;
    cin >> c1>> w1;
    cin >> c2>>w2;
    cin >> c3>>w3;
    for(int i=0; i<100; i++){
        if(i%3 ==0){
            int pour= min(w1, c2-w2);
            w1 -= pour;
            w2+= pour;
        }
        if(i%3 ==1){
            int pour= min(w2, c3-w3);
            w2 -= pour;
            w3+= pour;
        }
        if(i%3 ==2){
            int pour= min(w3, c1-w1);
            w3 -= pour;
            w1+= pour;
        }
    }
    cout << w1<<endl<<w2<<endl<<w3;
}