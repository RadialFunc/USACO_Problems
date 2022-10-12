#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<char> check(char a, char b, char c){
  vector<char> fin;

  if (a==b && b==c){
    fin.push_back(a); return fin;
  }
  else if(a==b){
    if(int(a) > int(c)){
    fin.push_back(a); 
    fin.push_back(c);}
    else{
      fin.push_back(c);
      fin.push_back(a);
    }
    return fin;
  }
  else if(b==c){
    if(int(a) > int(b)){
    fin.push_back(a); 
    fin.push_back(b);}
    else{
      fin.push_back(b);
      fin.push_back(a);
    }
    return fin;
  }
  else if(a==c){
    if(int(a) > int(b)){
    fin.push_back(a); 
    fin.push_back(b);}
    else{
      fin.push_back(b);
      fin.push_back(a);
    }
    return fin;
  }else{
    fin.push_back('0');
    return fin;
  }
}

int main(){
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  char board[3][3];
  for(int i=0; i<3; i++){
    cin >> board[i][0]>> board[i][1]>>board[i][2];
  }
  vector<char> wrong;
  wrong.push_back('0');
  set<vector<char> > s;
  set<vector<char> > s2;
  for(int i=0; i<3; i++){
    vector<char> val = check(board[0][i], board[1][i], board[2][i]);
    if(val!= wrong){
      if(val.size()==1) s.insert(val);
      else s2.insert(val);
    }
  }
  for(int i=0; i<3; i++){
    vector<char> val = check(board[i][0], board[i][1], board[i][2]);
    if(val!= wrong){
      if(val.size()==1) s.insert(val);
      else s2.insert(val);
    }
  }
  vector<char> val = check(board[0][0], board[1][1], board[2][2]);
  if(val != wrong){
    if(val.size()==1) s.insert(val);
    else s2.insert(val);
  }
  vector<char> val2 = check(board[2][0], board[1][1], board[0][2]);
  if(val2 != wrong){
    if(val.size()==1) s.insert(val);
    else s2.insert(val);
  }
  cout << s.size() << endl<<s2.size()<<endl;

}