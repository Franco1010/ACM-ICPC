#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define ENDL '\n'
#define MOD 1000000007
using namespace std;
typedef long long int lli;
vector<lli>fb;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  lli c,a,b,limit=pow(2, 32);
  a=1,b=1;
  fb.push_back(1);
  fb.push_back(1);
  while(a<limit){
    c=a+b;
    a=b;b=c;
    fb.push_back(c);
  }
  while(cin>>c){
    if(c==-1)break;
    cout<<fb[c+1]-1<<' '<<fb[c+1]-1+fb[c]<<ENDL;
  }
  return 0;
}
