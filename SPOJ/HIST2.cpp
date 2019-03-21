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
const int N = 16;
lli n;
int v[N];
int dp[N][1<<N];
int dpn[N][1<<N];

int solve(int mask, int ind){
  int &res = dp[ind][mask];
  if(res != -1) return dp[ind][mask];

  if(mask == (1 << n) - 1){
    dpn[ind][mask] = 1;
    res = v[ind];
    return res;
  }
  int aux;
  res = 0;
  Forn(i, n){
    if(!(mask & (1 << i))){
      aux = solve(mask | (1 << i), i) + abs(v[ind] - v[i]);
      if(aux > res){
        res = aux;
        dpn[ind][mask] = dpn[i][mask | (1 << i)];
      }
      else if(aux == res) dpn[ind][mask] += dpn[i][mask | (1 << i)];
    }
  }
  return res;
}

int main(){ _
  lli res = 0, cnt = 0, aux;
  while(cin >> n, n){
    res = cnt = 0;
    Forn(i, n) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    Forn(i, n){
      aux = solve(1 << i, i) + v[i];
      if(aux > res){
        res = aux;
        cnt = dpn[i][1 << i];
      }
      else if(aux == res) cnt += dpn[i][1 << i];
    }
    cout << res + (2*n) << ' ' << cnt << ENDL;
  }
  return 0;
}
