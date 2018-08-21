#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<set>
#include<queue>
typedef long long ll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define pb push_back
#define TAM 1001
using namespace std;

int main(){
  int n,m,k,l;
  cin>>n>>m;
  k=m+360-n;
  k%=360;
  l=n+360-m;
  l%=360;
  if(k<=l)cout<<k<<'\n';
  else cout<<-l<<'\n';


}
