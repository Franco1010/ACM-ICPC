//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl
#define lower(x, y) (lower_bound(all(x), y) - (x).begin())
#define upper(x, y) (upper_bound(all(x), y) - (x).begin())
#define ENDL '\n'

typedef long long lli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;

lli n;
vector<bool>vis;
vector<int>v[100];
void dfs(string &s){
  if(sz(s)==n){
    For(i,0,n-1,1)cout<<s[i]<<" ";cout<<ENDL;
  }
  Forn(i,n){
    bool saltar=false;
    if(!vis[i]){
      if(!v[i].empty())
        for(int pre:v[i])
          if(!vis[pre]){
            saltar=true;
            break;
          }
      if(saltar)continue;
      s.pb((char)i+'0');
      vis[i]=true;
      dfs(s);
      vis[i]=false;
      s.pop_back();
    }
  }
}

int main(){ _
  lli t,r,aux;
  cin>>t;
  while(t--){
    cin>>n;
    vis.resize(n+5,false);
    Forn(i,n){
      cin>>r;
      v[i].resize(0);
      Forn(j,r){
        cin>>aux;
        v[i].pb(aux);
      }
    }
    string x="";
    dfs(x);
  }
  return 0;
}
