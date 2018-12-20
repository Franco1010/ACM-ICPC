//https://codeforces.com/contest/1023/problem/B
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
  long long a,b,aux;
  cin>>a>>b;
  if(a>=b){
    if(b&1){
      cout<<b/2<<'\n';
    }
    else cout<<(b/2)-1<<'\n';
  }
  else{
    aux=a-(b/2);
    if(aux>=0)cout<<aux<<'\n';
    else cout<<"0\n";
  }
}
