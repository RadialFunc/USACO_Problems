#include <iostream>
#include <vector>
using namespace std;

vector<int> cows;

bool check(int num){
    for (size_t i=0; i<cows.size(); i++){
        if(num == cows[i]) return false;
    }
    return true;
}

int convert(string cow){
    if(cow=="Bessie") return 0;
    if(cow=="Elsie") return 1;
    if(cow=="Daisy") return 2;
    if(cow=="Gertie") return 3;
    if(cow=="Annabelle") return 4;
    if(cow=="Maggie") return 5;
    if(cow=="Henrietta") return 6;
}

string conv(int cow){
    if(cow==0) return "Bessie";
    if(cow==1) return "Elsie";
    if(cow==2) return "Daisy";
    if(cow==3) return "Gertie";
    if(cow==4) return "Annabelle";
    if(cow==5) return "Maggie";
    if(cow==6) return "Henrietta";
}

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int arr[7];
    for(int i=0; i<7; i++){
        arr[i] = 0;
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string cow;
        int milk;
        cin >> cow>> milk;
        int cown = convert(cow);
        arr[cown] += milk;
    }
    int least = arr[0];
    for(int i=0; i<7; i++){
        if(arr[i] <least) least = arr[i];
    }
    for(int i=0; i<7; i++){
        if (arr[i] == least) cows.push_back(i);
    }
    int nleast = 10000;
    int howmany=0;
    for(int i=0; i<7; i++){
        if (check(i)){
            if(arr[i]<nleast) nleast =arr[i];
        }
    }
    vector<int> winners;
    for(int i=0; i<7;i++){
        if(arr[i] == nleast){
            winners.push_back(i);
            howmany++;
        }

    }
    if(howmany !=1){
        cout << "Tie";
    }else{
        cout << conv(winners[0]);
    }


}