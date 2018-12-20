//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define empty(x) (x).empty()
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define debug(x) cout << #x"=" << x << endl
#define lower(x, y) (lower_bound(all(x), y) - (x).begin())
#define upper(x, y) (upper_bound(all(x), y) - (x).begin())
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;

lli n;
const int N = 1e4 + 5;
const int M = 125;
const int K = 7;
const double inf = numeric_limits<double>::max();
unordered_map<int, double> dp[N][K];
lli times[N];
double costs[N];

double descuento(double x, int k){
  if( k == 0 ) return x;
  if( k == 1 ) return x * 0.5;
  return x * 0.25;
}

double descuentos(int i, int j){
  double x =  0.00;
  For(k, i, j, +1){
    x += descuento(costs[k], k - i);
  }
  return x;
}

double f(int i, int t, int k){//i = elem, t = tiempo acumulado, k = descuento
  if( i == n ) return 0;
  double &ans = dp[i][k][t];
  if( ans == 0.00 ){
    double aplicar = inf; // Aplicas porque aún no tienes los k descuentos hechos
    double no = inf; // No alcanzas a otro descuento
    double rico = inf; // No aplicas porque eres rico

    if( t >= 120 or k > 5 ){
      ans = f(i + 1, times[i], 1) + descuento(costs[i], 0);
      return ans;
    }
    aplicar = f(i + 1, t + times[i], k + 1) + descuento(costs[i], k);
    rico = f(i + 1, times[i], 1) + descuento(costs[i], 0);

    ans = min(aplicar, rico);
  }
  return ans;
}

int main(){ _
  cin >> n;
  Forn(i, n){
    cin >> times[i] >> costs[i];
  }
  f(0,0,0);
  cout << fixed << setprecision(2) << dp[0][0][0] << ENDL;
  return 0;
}
