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

const double pi = acos(-1);
const double eps = 1e-9;
const lli mod = 1e9 + 7;
const lli llinf = (1ll << 60);
//const int inf = (1 << 30);

const int N = 5e5 + 5;
const int inf = 1e9 + 9;

struct Edge{
  int v;
  int dist;
};

vector<Edge> g[N];
int dists[N];
priority_queue<ii> pq; // {dist, node}
int n, m, q;

ii dijkstra(int start){
  Forn(u, n){
    dists[u] = inf;
  }
  dists[start] = 0;
  pq.push({0, start});
  int u;
  while( !pq.empty() ){
    tie(ignore, u) = pq.top();
    pq.pop();
    for(Edge &e: g[u]){
      if( dists[u] + e.dist < dists[e.v] ){
        dists[e.v] = dists[u] + e.dist;
        pq.push({ -dists[e.v], e.v});
      }
    }
  }
  int far = 0, cnt = 0;
  Forn(u, n){
    if( dists[u] == inf ) continue;
    if( dists[u] == far ){
      cnt++;
    }else if( dists[u] > far ){
      far = dists[u];
      cnt = 1;
    }
  }
  return {far, cnt};
}

int main(){ _
  int u, v, dist;
  int far, cnt;
  cin >> n >> m >> q;
  Forn(i, m){
    cin >> u >> v >> dist;
    g[u].pb({v, dist});
    g[v].pb({u, dist});
  }
  Forn(i, q){
    cin >> u;
    tie(far, cnt) = dijkstra(u);
    cout << far << " " << cnt << '\n';
  }
  return 0;
}
