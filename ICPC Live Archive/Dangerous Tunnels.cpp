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

template <typename T>
struct dinic{
  const static T flow_inf = numeric_limits<T>::max();

  struct edge{
    int u, v;
    int danger;
    T cap, flow = 0;

    edge(int u, int v, int danger, T cap): u(u), v(v), danger(danger), cap(cap){}
  };

  vector< vector<int> > g;
  vector<edge> edges;
  vector<int> dists, ptr;
  int s, t;
  int n, m = 0;

  dinic(int _n, int _s = 0, int _t = 0): n(_n + 2), s(_s), t(_t){
    g.resize(n + 5);
    dists.resize(n + 5);
    ptr.resize(n + 5);
  }

  void add_edge(int u, int v, int danger, T cap){
    edges.pb(edge(u, v, danger, cap));
    edges.pb(edge(v, u, danger, 0));
    g[u].pb(m);
    g[v].pb(m + 1);
    m += 2;
  }

  bool bfs(){
    fill(all(dists), -1);
    queue<int> que;
    que.push(s);
    dists[s] = 0;
    while( !que.empty() ){
      int u = que.front();
      que.pop();
      for(int id: g[u]){
        edge &e = edges[id];
        if( e.cap - e.flow <= 0 ){
          continue;
        }
        if( dists[e.v] == -1 ){
          dists[e.v] = dists[u] + 1;
          que.push(e.v);
        }
      }
    }
    return dists[t] != -1;
  }

  T dfs(int u, T flow = flow_inf){
    if( flow <= 0 ){
      return 0;
    }
    if( u == t ){
      return flow;
    }
    for(int &cid = ptr[u]; cid < size(g[u]); cid++){
      int id = g[u][cid];
      edge &e = edges[id];
      if( e.cap - e.flow <= 0 ){
        continue;
      }
      if( dists[u] + 1 == dists[e.v] ){
        T nflow = dfs(e.v, min(flow, e.cap - e.flow));
        if( nflow > 0 ){
          edges[id].flow += nflow;
          edges[id ^ 1].flow -= nflow;
          return nflow;
        }
      }
    }
    return 0;
  }

  void rebuild(int danger){
    For(id, 0, size(edges) - 1, +2){
      edges[id].cap = edges[id].danger <= danger;
      edges[id].flow = 0;
      edges[id ^ 1].cap = 0;
      edges[id ^ 1].flow = 0;
    }
  }

  T max_flow(){
    T flow = 0;
    while( bfs() ){
      fill(all(ptr), 0);
      while( T nflow = dfs(s) ){
        flow += nflow;
      }
    }
    return flow;
  }
};

int main(){ _
  int n, m, k, t = 1;
  while( cin >> n, n != 0 ){
    if( t > 1 ){
      cout << '\n';
    }
    cin >> m;
    dinic<int> g(n, 0, n + 1);
    Forn(i, m){
      int u, v, danger;
      cin >> u >> v >> danger;
      if( v < u ){
        swap(u, v);
      }
      g.add_edge(u, v, danger, 1);
    }
    cin >> k;
    int low = 0, high = 1e5;
    while( low + 1 < high ){
      int mid = (low + high) / 2;
      g.rebuild(mid);
      if( g.max_flow() >= k ){
        high = mid;
      }else{
        low = mid;
      }
    }
    cout << "Case " << t++ << ": ";
    g.rebuild(high);
    if( g.max_flow() >= k ){
      cout << high;
    }else{
      cout << "no solution";
    }
  }
  return 0;
}
