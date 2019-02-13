// touch {a..l}.in; tee {a..l}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

const int N = 1e5 + 5;
const lli inf = 1e18;

struct edge{
  int v;
  lli dist;
};

vector<edge> g[N];
lli dists[N]; // Recordar el tipo de dato
priority_queue<pair<lli,int>> pq; // {dist, node}

lli n, r, s, d, t;
lli dijkstra(int s, int d){
  For1(i, n){
    dists[i] = inf;
  }
  pq.push({0, s});
  dists[s] = 0;
  while(!pq.empty()){
    lli u = pq.top().second;
    pq.pop();
    for(edge &e: g[u]){
      if(e.dist + dists[u] + 12 < dists[e.v]){
        dists[e.v] = e.dist + dists[u] + 12;
        pq.push({-dists[e.v], e.v});
      }
    }
  }
  return dists[d];
}

int main(){ _
  int u, v;
  lli dist;
  cin >> t;
  Forn(tt, t){
    cin >> n >> r >> s >> d;
    For1(u, n){
      g[u].clear();
    }
    Forn(i, r){
      cin >> u >> v >> dist;
      g[u].pb({v, dist});
      g[v].pb({u, dist});
    }
    cout << dijkstra(s, d) << ENDL;
  }
  return 0;
}
