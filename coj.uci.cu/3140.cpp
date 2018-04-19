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
  lli c,aux;
  vector<lli>nums;
  cin>>c;
  while(c--){
    cin>>aux;
    nums.push_back(aux);
  }
  sort(nums.begin(),nums.end());
  c=nums.size();
  for(aux=0;aux<c;aux++){
    cout<<nums[aux]<<ENDL;
  }
}
