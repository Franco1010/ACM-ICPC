#include <iostream>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int c,cont=0,i;
  bool x=true;
  string s;
  cin>>c;
  while (c--) {
    x=true;
    cin>>s;
    for(i = 0; i < s.size()-1; i++) {
      if (s[i]=='C' && s[i+1]=='D') {
        x=false;
        break;
      }
    }
    if (x) {
      cont++;
    }
  }
  cout<<cont<<'\n';
  return 0;
}
