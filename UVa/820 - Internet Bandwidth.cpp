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
struct edmonds_karp{
  const T flow_inf = numeric_limits<T>::max();

  vector< vector<bool> > g;
  vector< vector<T> > cap;
  vector<int> path;
  int s, t;
  int n;

  edmonds_karp(int _n): n(_n){
    g.resize(n + 5, vector<bool>(n + 5, false));
    cap.resize(n + 5, vector<T>(n + 5, 0));
    path.resize(n + 5);
  }

  void add_edge(int u, int v, T ncap){
    g[u][v] = true;
    g[v][u] = true;
    cap[u][v] += ncap;
    cap[v][u] += ncap;
  }

  T bfs(){
    fill(all(path), -1);
    queue< pair<int, T> > que;
    que.push({s, flow_inf});
    while( !que.empty() ){
      int u;
      T flow;
      tie(u, flow) = que.front();
      que.pop();
      For1(v, n){
        if( g[u][v] && path[v] == -1 && cap[u][v] > 0 ){
          path[v] = u;
          T nflow = min(flow, cap[u][v]);
          if( v == t ){
            return nflow;
          }
          que.push({v, nflow});
        }
      }
    }
    return 0;
  }

  T max_flow(){
    T flow = 0;
    while( T nflow = bfs() ){
      flow += nflow;
      for(int v = t; v != s; v = path[v]){
        int u = path[v];
        cap[u][v] -= nflow;
        cap[v][u] += nflow;
      }
    }
    return flow;
  }
};

int main(){ _
  int n, m, t = 1;
  while( cin >> n, n != 0 ){
    edmonds_karp<int> g(n);
    cin >> g.s >> g.t >> m;
    Forn(i, m){
      int u, v, cap;
      cin >> u >> v >> cap;
      g.add_edge(u, v, cap);
    }
    cout << "Network " << t++ << "\n";
    cout << "The bandwidth is " << g.max_flow() << ".\n\n";
  }
  return 0;
}
