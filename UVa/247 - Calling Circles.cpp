#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define debug(x) cout << #x": " << x << '\n';

#define fst first
#define snd second
#define pb push_back
#define lower lower_bound
#define upper upper_bound
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef unsigned long long ulli;
typedef pair<int, int> ii;

const int N = 30;

vector<int> g[N];
vector<int> rg[N];
map<string, int> mp;
vector<string> rmp;
bool vis[N];
vector<int> topological;
vector< vector<int> > components;
int n, m;

int compress(string &s){
  if( !mp.count(s) ){
    mp[s] = size(mp);
    rmp.pb(s);
  }
  return mp[s];
}

void dfs1(int u){
  vis[u] = true;
  for(int v: g[u]){
    if( !vis[v] ){
      dfs1(v);
    }
  }
  topological.pb(u);
}

void dfs2(int u, vector<int> &component){
  vis[u] = true;
  component.pb(u);
  for(int v: rg[u]){
    if( !vis[v] ){
      dfs2(v, component);
    }
  }
}

int main(){ _
  int tt = 1;
  while( cin >> n >> m, n + m != 0 ){
    Forn(u, n){
      g[u] = rg[u] = vector<int>();
    }
    mp = map<string, int>();
    rmp = vector<string>();
    Forn(id, m){
      string a, b;
      cin >> a >> b;
      int u = compress(a);
      int v = compress(b);
      g[u].pb(v);
      rg[v].pb(u);
    }
    fill_n(vis, n, false);
    topological = vector<int>();
    Forn(u, n){
      if( !vis[u] ){
        dfs1(u);
      }
    }
    reverse(all(topological));
    fill_n(vis, n, false);
    components = vector< vector<int> >();
    for(int u: topological){
      if( !vis[u] ){
        vector<int> component;
        dfs2(u, component);
        components.pb(component);
      }
    }
    cout << "Calling circles for data set " << tt++ << ":\n";
    Forn(i, size(components)){
      Forn(j, size(components[i])){
        int u = components[i][j];
        cout << rmp[u] << (j == size(components[i]) - 1 ? "\n": ", ");
      }
    }
  }
  return 0;
}
