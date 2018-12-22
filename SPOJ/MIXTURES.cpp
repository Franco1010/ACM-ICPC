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

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;
const lli inf = (1ll << 60);

const int N = 1e2 + 5;
lli sum[N][N];
lli dp[N][N];
vector<int> v;
lli mcm(int l, int r){
  lli &ans = dp[l][r];
  if(ans == -1){
    if(l == r) ans = 0;
    else if(l+1 == r) ans = v[l] * v[r];
    else{
      ans = inf;
      For(i, l, r, 1){
        ans = min(ans, mcm(l, i) + mcm(i+1, r) + sum[l][i] * sum[i+1][r]);
      }
    }
  }
  return ans;
}

int main(){ _
  lli n;
  while(cin >> n){
    v.resize(n);
    Forn(i, n) cin >> v[i];
    Forn(i, n+5){
      Forn(j, n+5){
        dp[i][j] = -1;
        if(i == j) sum[i][j] = v[i];
      }
    }
    Forn(i, n) For(j, i+1, n, 1) sum[i][j] = (sum[i][j-1] + v[j]) % 100;
    cout << mcm(0, n-1) << ENDL;
  }
  return 0;
}
