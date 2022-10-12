#include <iostream>
#include <vector>
using namespace std;

vector<vector<string> > animals;

int share(int a,int b){
    int total=0;
    vector<string> first = animals[a];
    vector<string> second = animals[b];
    for(unsigned int i=0; i<first.size(); i++){
        bool check=false;
        for(unsigned int j=0; j<second.size(); j++){
            if (first[i]==second[j])check=true;
        }
        if(check==true) total++;
    }
    return total;
}

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        vector<string> animal;
        string type; 
        int k;
        cin >> type>>k;
        for(int j=0; j<k; j++){
            string charac;
            cin >> charac;
            animal.push_back(charac);
        }
        animals.push_back(animal);
    }
    int maxs =0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int val = share(i,j);
            if (val > maxs) maxs=val;
        }
    }
    cout << maxs+1;

}