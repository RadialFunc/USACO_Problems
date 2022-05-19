#include <iostream>

using namespace std;

struct die {
    int faces[4];
};

int beats(die die1, die die2){
    int d1=0;
    int d2=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(die1.faces[i] > die2.faces[j]) d1++;
            else if(die1.faces[i] < die2.faces[j]) d2++;
        }
    }
    if(d1==d2) return 0;
    else if(d1>d2) return 1;
    else return 2;
}

int main(){

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        bool check=false;
        die die1, die2;
        cin >> die1.faces[0]>> die1.faces[1]>>die1.faces[2]>>die1.faces[3] >> die2.faces[0]>> die2.faces[1]>>die2.faces[2]>>die2.faces[3];
        for(int j=1; j<=10; j++){
            for(int k=1; k<=10; k++){
                for(int l=1; l<=10; l++){
                    for(int m=1; m<=10; m++){
                        die die3;
                        die3.faces[0] = j; die3.faces[1] = k; die3.faces[2] = l; die3.faces[3] = m;
                        if(beats(die1, die2) != beats(die1, die3) && beats(die2, die3) != beats(die2, die1) && beats(die1, die3) !=0 && beats(die2,die3) !=0 && beats(die2, die1)!=0){check=true;} 
                    }
                }
            }
        }
        if(check) cout << "yes" <<endl;
        else cout << "no"<<endl;
    }
}