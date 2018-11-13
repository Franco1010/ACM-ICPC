//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl
#define lower(x, y) (lower_bound(all(x), y) - (x).begin())
#define upper(x, y) (upper_bound(all(x), y) - (x).begin())
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;

lli r,c;
int mapa[105][105];
const int x[4]={0,0,1,-1};
const int y[4]={1,-1,0,0};
int dfs(int i,int j){
  mapa[i][j]=2;
  int res=1;
  Forn(k,4){
    int nx=i+x[k];
    int ny=j+y[k];
    if(0<=nx and nx<r and 0<=ny and ny<c and mapa[nx][ny]==1){
      res+=dfs(nx,ny);
    }
  }
  return res;
}
int main(){ _
  lli t,g,aux,res=0,resC=0;
  cin>>t>>g>>r>>c;
  Forn(i,r){
    Forn(j,c){
      cin>>mapa[i][j];
    }
  }
  Forn(i,r){
    Forn(j,c){
      if(mapa[i][j]==1){
        aux=dfs(i,j);
        if(aux>=t)res+=aux*g-t*g,resC++;
      }
    }
  }
  cout<<resC<<' '<<res<<ENDL;
  return 0;
}
