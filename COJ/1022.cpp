#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#define ENDL '\n'
#define MOD 1000000007
using namespace std;
typedef long long int lli;
lli nums[1000000];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  lli i,l,c,d,aux,cont;
  bool x=true;
  cin>>c;
  while(c--){
    cont=0;
    cin>>d;
    for(i=0;i<d;i++){
      cin>>nums[i];
    }
    x=true;
    while(x){
      x=false;
      for(i=0;i<d-1;i++){
        if(nums[i]>nums[i+1]){
          swap(nums[i],nums[i+1]);
          cont++;
          x=true;
        }
      }
    }
    cout<<"Optimal train swapping takes "<<cont<<" swaps."<<ENDL;
  }
  return 0;
}
