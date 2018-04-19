#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#define ENDL '\n'
#define MOD 1000000007
using namespace std;
typedef long long int lli;

lli factorial(lli n){
  if(n==0)return 1;
  return n * factorial(n-1);
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  lli c,aux,i,res=0;
  vector<lli>g;
  cin>>c;
  while(c--){
    cin>>aux;
    g.push_back(aux);
  }
  sort(g.begin(),g.end());
  c=g.size();
  c=c/2+1;
  for(i=0;i<c;i++){
    res+=g[i]/2+1;
  }
  cout<<res<<ENDL;
}
