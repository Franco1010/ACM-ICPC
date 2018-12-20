#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i += c)
#define Rof(i, a, b, c) for(int i = a; i >= b; i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define For1(i, n) For(i, 1, n, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
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

const int N = 3e5 + 5;

struct edge{
  int x, y;
  lli gasoline;
};

vector<int> g[N];
vector<edge> edges;
lli gasoline[N];
lli dp[N];
lli ans;
int n, m;

void dfs(int x, int pr = -1){
  dp[x] = gasoline[x];
  ans = max(ans, gasoline[x]);
  for(int id: g[x]){
    edge &e = edges[id];
    int y = e.x ^ e.y ^ x;
    if( y == pr ) continue;
    dfs(y, x);
    dp[y] -= e.gasoline;
    ans = max(ans, dp[x] + dp[y]);
    dp[x] = max(dp[x], dp[y] + gasoline[x]);
  }
}

int main(){ _
  cin >> n;
  For1(x, n){
    cin >> gasoline[x];
  }
  m = n - 1;
  Forn(id, m){
    int x, y;
    lli gas;
    cin >> x >> y >> gas;
    edges.pb({x, y, gas});
    g[x].pb(id);
    g[y].pb(id);
  }
  ans = 0;
  dfs(1);
  cout << ans << '\n';
  return 0;
}
