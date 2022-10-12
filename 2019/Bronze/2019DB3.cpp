#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int convert(string cow){
    if(cow=="Beatrice"){
        return 1;
    }else if(cow=="Belinda"){
        return 2;
    }else if(cow=="Bella"){
        return 3;
    }else if(cow=="Bessie"){
        return 4;
    }else if(cow=="Betsy"){
        return 5;
    }else if(cow=="Blue"){
        return 6;
    }else if(cow=="Buttercup"){
        return 7;
    }else if(cow=="Sue"){
        return 8;
    }
}


string convert2(int cow){
    switch(cow){
        case 1:
            return "Beatrice";
            break;
        case 2:
            return "Belinda";
            break;
        case 3:
            return "Bella";
            break;
        case 4:
            return "Bessie";
            break;
        case 5:
            return "Betsy";
            break;
        case 6:
            return "Blue";
            break;
        case 7:
            return "Buttercup";
            break;
        case 8:
            return "Sue";
            break;
    }
}

int indexOf(vector<int> v, int k){
    for (int i=0; i<8; i++){
        if (v[i] ==k){
            return i;
        }
    }
}

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<int> v;
    for (int i=1; i<9;i++){
        v.push_back(i);
    }
    int n; 
    cin >> n;
    vector<vector<int> > conditions;
    for(int i=0; i<n; i++){
        string first, a2, a3, a4, a5, second;
        cin >> first >> a2>>a3>> a4>>a5>>second;
        int val, val1;
        val = convert(first);
        val1 = convert(second);
        vector<int> condition;
        condition.push_back(val1);
        condition.push_back(val);
        conditions.push_back(condition);  
    }
    vector<int> fin;
    do{
        vector<int> pos;
        for(int i=1; i<9; i++){
            pos.push_back(indexOf(v, i));
        }
        bool check=true;
        for(int i=0; i<n; i++){
            vector<int> condition = conditions[i];
            int num = condition[0];
            int num1 = condition[1];
            if (!(pos[num-1]==pos[num1-1]+1 || pos[num-1] == pos[num1-1]-1)){
                check=false;
                break;
            }
        }

        if (check==true){
            fin = v;
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    for (int i=0; i<8; i++){
        cout << convert2(fin[i]) <<endl;
    }

}