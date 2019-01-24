#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
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

const lli mod = 1e9 + 7;
const int N = 1e6 + 5;
lli fact[N];
lli inv_fact[N];

lli choose(lli n, lli k){
  return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

lli powmod(lli x, lli y){
  lli r = 1;
  while( y > 0 ){
    if( y & 1 ){
      r = r * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}

void factorials(){ // n! y inv(n!)
  fact[0] = 1ll;
  For1(i, N - 1){
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  inv_fact[N - 1] = powmod(fact[N - 1], mod - 2);
  Rof(i, N - 2, 0, -1){
    inv_fact[i] = 1ll * inv_fact[i + 1] * (i + 1) % mod;
  }
}

int main(){ _
  factorials();
  lli n, a, b, d;
  while( cin >> n >> a >> b >> d ){
    if( n == 0 ) break;
    lli ans = 1;
    ans *= choose(n, a);
    //debug(choose(n, a));
    ans %= mod;
    //debug(powmod(choose(b, d), a));
    ans *= (powmod(choose(b, d), a) % mod);
    ans %= mod;
    cout << ans << ENDL;
  }
  return 0;
}
