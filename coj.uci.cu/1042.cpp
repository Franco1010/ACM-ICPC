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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout<<fixed<<setprecision(1);
  lli c,i;
  double a,b,d,res=0;
  cin>>c;
  for(i=0;i<c;i++){
    cin>>a>>b;
    d=a-((a*a+b*b)/(2*a));
    cout<<d<<ENDL;
    res+=d;
  }
  cout<<res/double(c)<<ENDL;
}
