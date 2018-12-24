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
 
const int N = 105;
const int C = 100;
 
const lli inf = numeric_limits<lli>::max();
int mixtures[N];
lli sums[N];
lli dp[N][N];
int n;
 
lli smoke(int l, int r){
  return l <= r ? (sums[r] - sums[l - 1] + C) % C: 0ll;
}

int main(){ _
  while( cin >> n ){
    For1(i, n){
      cin >> mixtures[i];
      sums[i] = sums[i - 1] + mixtures[i];
      sums[i] %= C;
    }
    For1(l, n){
      dp[l][l] = 0;
    }
    For(length, 2, n, +1){
      For1(l, n - length + 1){
        int r = l + length - 1;
        dp[l][r] = dp[l + 1][r] + smoke(l, l) * smoke(l + 1, r);
        For(k, l + 1, r, +1){
          dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + smoke(l, k) * smoke(k + 1, r));
        }
        dp[l][r] = min(dp[l][r], dp[l][r - 1] + smoke(l, r - 1) * smoke(r, r));
      }
    }
    cout << dp[1][n] << '\n';
  }
  return 0;
}
