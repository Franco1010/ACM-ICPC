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
priority_queue<ii> pq;
lli dists[N];
lli n, m, start, mxdist;

lli dijkstra(){
  For1(u, n){
    dists[u] = inf;
  }
  dists[start] = 0;
  pq.push({0, start});
  while( !pq.empty() ){
    int u;
    tie(ignore, u) = pq.top();
    pq.pop();
    for(edge &e: g[u]){
      if( dists[u] + e.dist < dists[e.v] ){
        dists[e.v] = dists[u] + e.dist;
        pq.push({ -dists[e.v], e.v});
      }
    }
  }
  lli cnt = 0;
  For1(u, n){
    cnt += dists[u] == mxdist;
    for(edge &e: g[u]){
      int need = mxdist - dists[u];
      if( need <= 0 or need >= e.dist) continue;
      int remain = e.dist - need;
      if( mxdist < dists[e.v] + remain ) cnt++;
      else if( mxdist == dists[e.v] + remain && u < e.v ) cnt++;
    }
  }
  return cnt;
}

int main(){ _
  cin >> n >> m >> start;
  Forn(i, m){
    int u, v; lli dist;
    cin >> u >> v >> dist;
    g[u].pb({v, dist});
    g[v].pb({u, dist});
  }
  cin >> mxdist;
  cout << dijkstra() << ENDL;
  return 0;
}
