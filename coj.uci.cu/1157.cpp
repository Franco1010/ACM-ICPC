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
  lli i;
  double res=0;
  cout<<fixed<<setprecision(9);
  cout<<"n e"<<ENDL<<"- -----------"<<ENDL;
  cout<<"0 1"<<ENDL;
  cout<<"1 2"<<ENDL;
  cout<<"2 2.5"<<ENDL;
  cout<<"3 2.666666667"<<ENDL;
  cout<<"4 2.708333333"<<ENDL;
  cout<<"5 2.716666667"<<ENDL;
  cout<<"6 2.718055556"<<ENDL;
  cout<<"7 2.718253968"<<ENDL;
  cout<<"8 2.718278770"<<ENDL;
  cout<<"9 2.718281526"<<ENDL;  
}
