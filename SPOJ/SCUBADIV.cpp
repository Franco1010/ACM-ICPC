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
const int inf = (1 << 30);
const int N = 1005;

struct cylinder{
  int oxygen, nitrogen;
  int weight;
};

cylinder c[N];
cylinder need;
int dp[N][22][80]; // {i, oxygen, nitrogen} = min weight
int n;

int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    cin >> need.oxygen >> need.nitrogen;
    cin >> n;
    For1(i, n){
      cin >> c[i].oxygen >> c[i].nitrogen >> c[i].weight;
    }
    Forn(i, n + 1){
      Forn(oxy, need.oxygen+1){
        Forn(nit, need.nitrogen+1){
          dp[0][oxy][nit] = oxy == 0 && nit == 0 ? 0: inf;
        }
      }
    }
    For1(i, n){
      Forn(oxy, need.oxygen + 1){
        Forn(nit, need.nitrogen + 1){
          dp[i][oxy][nit] = min(dp[i - 1][oxy][nit],
              dp[i - 1][max(0, oxy - c[i].oxygen)][max(0, nit - c[i].nitrogen)] + c[i].weight);
        }
      }
    }
    cout << dp[n][need.oxygen][need.nitrogen] << '\n';
  }
  return 0;
}
