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

const int N = 1005;

vector<int> g[N];
vector<ii> edges;
set<ii> bridges;
int tin[N];
int fup[N];
bool vis[N];
int path[N];
int timer;
int n, m;

void bridges_dfs(int u, int pr = -1){
  path[u] = pr;
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
    path[u] = -1;
  }
  For1(u, n){
    if( !vis[u] ){
      bridges_dfs(u);
    }
  }
}

int main(){ _
  int tt = 1;
  while( cin >> n >> m ){
    if( n + m == 0 ){
      break;
    }
    edges = vector<ii>();
    bridges = set<ii>();
    For1(u, n){
      g[u] = vector<int>();
    }
    Forn(id, m){
      int u, v;
      cin >> u >> v;
      edges.pb({u, v});
      g[u].pb(v);
      g[v].pb(u);
    }
    find_bridges();
    cout << tt++ << "\n\n";
    for(ii &e: edges){
      int u, v;
      tie(u, v) = e;
      if( bridges.count(make_pair(min(u, v), max(u, v))) ){
        cout << u << ' ' << v << '\n';
        cout << v << ' ' << u << '\n';
      }else{
        if( tin[u] > tin[v] ){
          swap(u, v);
        }
        if( path[v] == u ){
          cout << u << ' ' << v << '\n';
        }else{
          cout << v << ' ' << u << '\n';
        }
      }
    }
    cout << "#\n";
  }
  return 0;
}
