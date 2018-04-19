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
lli j[10];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  lli c,i,sum,k;
  cin>>c;
  for(k=1;k<=c;k++){
    sum=0;
    for(i=0;i<10;i++){
      cin>>j[i];
    }
    sort(j,j+10);
    for(i=1;i<9;i++){
      sum+=j[i];
    }
    cout<<k<<' '<<sum<<ENDL;
  }
}
