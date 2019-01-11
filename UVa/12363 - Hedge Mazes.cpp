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

const int N = 1e4 + 5;

vector<int> g[N];
set<ii> bridges;
int tin[N];
int fup[N];
bool vis[N];
int timer;
int n, m, q;

void bridges_dfs(int u, int pr = -1){
  vis[u] = true;
  tin[u] = fup[u] = ++timer;
  for(int v: g[u]){
    if( v == pr ){
      continue;
    }
    if( !vis[v] ){
      bridges_dfs(v, u);
      fup[u] = min(fup[u], fup[v]);
      if( fup[v] > tin[u] ){
        bridges.insert(make_pair(min(u, v), max(u, v)));
      }
    }else{
      fup[u] = min(fup[u], tin[v]);
    }
  }
}

void find_bridges(){
  timer = 0;
  For1(u, n){
    tin[u] = -1;
    fup[u] = -1;
    vis[u] = false;
  }
  For1(u, n){
    if( !vis[u] ){
      bridges_dfs(u);
    }
  }
}

class dsu{
public:
  vector<int> pr;

  dsu(int _n){
    pr.resize(_n + 5);
    iota(all(pr), 0);
  }

  int find(int x){
    return pr[x] == x ? x: pr[x] = find(pr[x]);
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if( x != y ){
      pr[x] = y;
      return true;
    }
    return false;
  }
};

int main(){ _
  while( cin >> n >> m >> q ){
    if( n + m + q == 0 ){
      break;
    }
    bridges = set<ii>();
    For1(u, n){
      g[u] = vector<int>();
    }
    Forn(id, m){
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    find_bridges();
    dsu dg(n);
    for(auto it: bridges){
      int u, v;
      tie(u, v) = it;
      dg.unite(u, v);
    }
    Forn(i, q){
      int u, v;
      cin >> u >> v;
      cout << "NY"[dg.find(u) == dg.find(v)] << '\n';
    }
    cout << "-\n";
  }
  return 0;
}
