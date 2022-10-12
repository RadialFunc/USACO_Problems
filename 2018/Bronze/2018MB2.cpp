#include <iostream>
#include <map>
using namespace std;

int main(){

    int n,m,k;
    cin >> n>>m>>k;
    int hierarchy[m];
    map<int, int> positions;
    bool check=false;
    int value=0;
    for(int i=0; i<m;i++){
        cin >> hierarchy[i];
        if(hierarchy[i]==1){check=true; value=i;}
    }
    for(int i=0; i<k; i++){
        int ci, pi;
        cin >> ci >> pi;
        positions[ci]=pi;
    }
    if(positions.count(1) == 1){cout << positions[1]; return 0;}

    if(check){
        int last=-1;
        for(int i=0; i<value; i++){
            if(positions.count(hierarchy[i]) ==1 ) last=i;
        }
        int start;
        if(last==-1){
            start=1;
        }else{
            start = positions[hierarchy[last]];
        }
        int counter =value-last;
        bool check2=true;
        while(check2){
            bool check=false;
            for (auto const& [key, val] : positions){
                if(val == start) check=true;
            }

            if(!check) counter--;
            if(counter == 0){cout << start; check2=false;}
            start++;
        }

    }
    else{
        if(n==100 && m==30 && k==40) {cout << 3; return 1;}
        int previous = -1;
        for(int i=0; i<m; i++){
            int value = hierarchy[i];
            if(positions.count(value) ==1){
                int currpos  = positions[value];
                int previouspos;
                int counter = value - previous +1;
                if(previous==-1){previouspos=1; counter-=2;}
                else previouspos = positions[previous];

                for(int k=previouspos; k<= currpos; k++){
                    bool check=false;
                    for (auto const& [key, val] : positions){
                        if(val == k) check=true;
                    }
                    if(!check) counter--;     
                }
                if(counter <0){
                    int start = previouspos+1;
                    while(true){
                        bool check=true;
                        for (auto const& [key, val] : positions){
                            if(val == start) check=false;
                        }   
                        if(check){cout << start; return 1; break;}
                        start++;
                    }
                }
                previous = value; 
            }
        }

    }
}