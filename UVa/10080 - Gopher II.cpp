#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
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

const int N = 105;
const int inf = 1e9;

struct hopcroft_karp{
  vector< vector<int> > g;
  vector<int> dists;
  vector<int> match;
  int n, m = 0;

  hopcroft_karp(int _n): n(_n + 2){
    g.resize(n + 5);
    dists.resize(n + 5);
    match.resize(n + 5, 0);
  }

  void add_edge(int u, int v){
    g[u].pb(v);
    g[v].pb(u);
    m += 2;
  }

  bool bfs(){
    queue<int> que;
    For1(u, n - 1){
      if( match[u] ){
        dists[u] = inf;
      }else{
        dists[u] = 0;
        que.push(u);
      }
    }
    dists[0] = inf;
    while( !que.empty() ){
      int u = que.front();
      que.pop();
      if( u != 0 ){
        for(int v: g[u]){
          if( dists[u] + 1 < dists[match[v]]){
            dists[match[v]] = dists[u] + 1;
            que.push(match[v]);
          }
        }
      }
    }
    return dists[0] != inf;
  }

  bool dfs(int u){
    if( u != 0 ){
      for(int v: g[u]){
        if( dists[u] + 1 == dists[match[v]] && dfs(match[v]) ){
          match[u] = v;
          match[v] = u;
          return true;
        }
      }
      dists[u] = inf;
      return false;
    }
    return true;
  }

  int max_matching(){
    int matching = 0;
    while( bfs() ){
      For1(u, n){
        if( !match[u] && dfs(u) ){
          matching++;
        }
      }
    }
    return matching;
  }
};

struct coord{
  double x, y;
};

coord gophers[N], holes[N];
double mx_time, vel;

int main(){ _
  int n, m;
  while( cin >> n >> m >> mx_time >> vel ){
    Forn(i, n){
      double x, y;
      cin >> x >> y;
      gophers[i] = {x, y};
    }
    Forn(i, m){
      double x, y;
      cin >> x >> y;
      holes[i] = {x, y};
    }
    hopcroft_karp g(n + m);
    Forn(i, n){
      Forn(j, m){
        coord &go = gophers[i], &ho = holes[j];
        double dist = hypot(go.x - ho.x, go.y - ho.y);
        if( dist / vel <= mx_time ){
          g.add_edge(i + 1, n + j + 1);
        }
      }
    }
    cout << n - g.max_matching() << '\n';
  }
  return 0;
}
