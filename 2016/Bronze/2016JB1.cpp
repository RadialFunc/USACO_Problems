#include <iostream>
using namespace std;

int main(){
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int bb, ab, bs, as, bg, ag, bp, ap;
    int probs, prosg, progp;
    cin >> bb>>ab;
    cin >> bs >> as;
    cin >> bg >> ag;
    cin >> bp>>ap;
    progp = ap-bp;
    ag += progp;
    prosg = ag-bg;
    as += prosg;
    probs = as-bs;
    cout << probs << endl<< prosg<<endl <<progp;
}