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

vector<int> g[N], rg[N];
vector<int> topological;
bool vis[N];
int n, m;

void dfs1(int u){
  vis[u] = true;
  for(int v: g[u]){
    if( !vis[v] ){
      dfs1(v);
    }
  }
  topological.pb(u);
}

void dfs2(int u){
  vis[u] = true;
  for(int v: g[u]){
    if( !vis[v] ){
      dfs2(v);
    }
  }
}

int main(){ _
  while( cin >> n >> m ){
    Forn(u, n + 1){
      g[u] = rg[u] = vector<int>();
    }
    Forn(id, m){
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      rg[v].pb(u);
    }
    topological = vector<int>();
    fill_n(vis, n + 1, false);
    Forn(u, n){
      if( !vis[u] ){
        dfs1(u);
      }
    }
    reverse(all(topological));
    int components = 0;
    fill_n(vis, n + 1, false);
    Forn(u, n){
      if( !vis[u] ){
        dfs2(u);
        components++;
      }
    }
    cout << components - 1 << '\n';
  }
  return 0;
}
