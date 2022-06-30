#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long int n;
  string s;
  cin >> n >> s;
  vector<long long int> other;
  long long int count = 0;
  long long int ans=0;
  char prev = s[0];
  for(int i=0; i<n; i++){
    if(s[i]==prev) count++;
    else{
      prev = s[i];
      other.push_back(count);
      count =1;
    }
    if(i==n-1){
      other.push_back(count);
    }
  }
  int l = other.size();
  if(l==1){ans=0;}
  else{
    for(int i=0; i<l; i++){
      if(i==0){
        ans+= other[1]-1;
      }else if(i==l-1){
        ans+= other[l-2]-1;
      }else{
        ans += other[i-1]-1 + other[i+1]-1;
        if(other[i]==1){
          ans += other[i-1]*other[i+1];
        }
      }
    }
  }
  cout << ans;  
}