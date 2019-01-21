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

const int N = 1e6 + 5;

int p[N];

void factorize_sieve(){
  iota(p, p + N, 0);
  For(i, 2, N - 1, +2){
    p[i] = 2;
  }
  For(i, 3, N - 1, +2){
    if( p[i] == i ){
      For(j, i, N - 1, +i){
        p[j] = i;
      }
    }
  }
}

vector<ii> factorize(int n){
  vector<ii> fact; // {p, k} = p^k
  while( n > 1 ){
    int k = 0, prime = p[n];
    while( n % prime == 0 ){
      n /= p[n];
      k++;
    }
    fact.pb({prime, k});
  }
  return fact;
}

template <typename T>
T fpow(T x, T y){
  T r = 1;
  while( y > 0 ){
    if( y & 1 ){
      r = r * x;
    }
    x = x * x;
    y >>= 1;
  }
  return r;
}

lli geo_sum(lli n, lli k){
  return (fpow(n, k + 1) - 1) / (n - 1);
}

int main(){ _
  factorize_sieve();
  lli tt;
  cin >> tt;
  Forn(t, tt){
    lli n;
    cin >> n;
    vector<ii> fact = factorize(n);
    lli ans = 1;
    for(auto it: fact){
      lli p, k;
      tie(p, k) = it;
      ans *= geo_sum(p, k);
    }
    cout << ans - n << '\n';
  }
  return 0;
}
