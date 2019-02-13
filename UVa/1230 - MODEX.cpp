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
#define mt make_tuple
#define mp make_pair
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

lli mpow(lli x, lli y, lli m){
  if(y == 0) return 1;
  lli res = 1;
  while(y > 0){
    if(y & 1) res = res * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return res;
}

int main(){ _
  lli t, x, y, n;
  cin >> t;
  Forn(tt, t){
    cin >> x >> y >> n;
    cout << mpow(x, y, n) << ENDL;
  }
  cin >> t;
  return 0;
}
