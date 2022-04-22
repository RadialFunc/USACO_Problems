#include <iostream>
#include <vector>
using namespace std;

int minimumchanges(vector<int> sleep,int  m, int sum, int maxs){
    int changes=m;
    int ne;
    if(sum==0) return 0;

    for(int i=1; i<=sum; i++){
        if(i>=maxs && sum %i==0){
            vector<int> sleepcop;
            for(int i=0; i<m;i++){
                sleepcop.push_back(sleep[i]);
            }
            int change=0;
            bool check=true;
            while (check && !sleepcop.empty()){
                int su=0;
                while (!sleepcop.empty() && su<i){
                    su+= sleepcop[0];
                    sleepcop.erase(sleepcop.begin());
                    change++;
                }
                if(sleepcop.empty() && su != i){
                    check=false;
                }else if(su> i){
                    check=false;
                }
                change--;
            }
            if(check==true){
                return change;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int sum=0;
        int maxs=0; 
        int m;
        cin >> m;
        vector<int> sleep;
        for(int j=0; j<m; j++){
            int k;
            cin >> k; 
            sum+=k;
            if(k>maxs) maxs=k;
            sleep.push_back(k);
        }
        int least = minimumchanges(sleep, m, sum, maxs);
        cout << least <<endl;
    }
}