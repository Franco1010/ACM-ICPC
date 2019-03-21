#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
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

const double pi = acos(-1);
const double eps = 1e-9;
const lli mod = 1e9 + 7;
const lli llinf = (1ll << 60);
//const int inf = (1 << 30);
const int N = 1e5 + 5;
lli n;
vector<int> g[N];
lli dp[2][N];

lli func(lli act, lli last, bool taked){
  lli &res = dp[taked][act];
  if(res != -1) return res;
  res = 0;
  if(taked){
    lli aux = 1;
    Forn(i, sz(g[act])) if(g[act][i] != last) res += func(g[act][i], act, false);
    Forn(i, sz(g[act])) if(g[act][i] != last) aux += func(g[act][i], act, true);
    res = min(res, aux);
  }else{
    res = 1;
    Forn(i, sz(g[act])) if(g[act][i] != last) res += func(g[act][i], act, true);
  }
  return res;
}

int main(){ _
  lli u, v;
  while(cin >> n){
    For1(i, n) g[i].clear();
    Forn(i, n-1){
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    memset(dp, -1, sizeof(dp));
    lli r1 = 1, r2 = 0;
    Forn(i, sz(g[1])) r1 += func(g[1][i], 1, true);
    Forn(i, sz(g[1])) r2 += func(g[1][i], 1, false);
    cout << min(r1, r2) << ENDL;
  }
  return 0;
}
