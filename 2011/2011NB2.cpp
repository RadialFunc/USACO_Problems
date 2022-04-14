#include <iostream>
#include <math.h>
using namespace std;

int basen(string str, int num){
    int length = str.length();
    int total=0;
    for (int i =0; i<length; i++){
        char a= str[i];
        int dig = a-'0';
        total+= dig*pow(num, length-1-i);
    }
    return total;
}

int main(){
    string b1, b2;
    cin >> b1;
    cin >> b2;
    int total = basen(b1, 2);
    int second = basen(b2,3);  
    for (int i=0; i<b2.length(); i++){
        for (int j=0; j< b1.length(); j++){
            if(b2[i]=="2"[0]){
                if(b1[j] == "1"[0]){
                    if (total-pow(2, b1.length()-1-j) == second-pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);
                    }else if (total-pow(2, b1.length()-1-j) == second-2*pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);                
                    }
                }else{
                    if (total+pow(2, b1.length()-1-j) == second-pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);
                    }else if (total+pow(2, b1.length()-1-j) == second-2*pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);                
                    }
                }
            }else if(b2[i]=="1"[0]){
                if(b1[j] == "1"[0]){
                    if (total-pow(2, b1.length()-1-j) == second-pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);
                    }else if (total-pow(2, b1.length()-1-j) == second+pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);                
                    }
                }else{
                    if (total+pow(2, b1.length()-1-j) == second-pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);
                    }else if (total+pow(2, b1.length()-1-j) == second+pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);                
                    }
                }
            }else{
                if(b1[j] == "1"[0]){
                    if (total-pow(2, b1.length()-1-j) == second+pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);
                    }else if (total-pow(2, b1.length()-1-j) == second+2*pow(3,b2.length()-1-i)){
                        cout << total-pow(2, b1.length()-1-j);                
                    }
                }else{
                    if (total+pow(2, b1.length()-1-j) == second+pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);
                    }else if (total+pow(2, b1.length()-1-j) == second+2*pow(3,b2.length()-1-i)){
                        cout << total+pow(2, b1.length()-1-j);                
                    }
                }
            }
        }

    }

}