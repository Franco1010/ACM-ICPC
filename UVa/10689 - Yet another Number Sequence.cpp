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

lli mod;

struct matrix{
  lli mat[2][2];

  matrix(int a, int b, int c, int d){
    mat[0][0] = a;
    mat[0][1] = b;
    mat[1][0] = c;
    mat[1][1] = d;
  }

  matrix(){}

  friend matrix operator * (matrix A, matrix B){
    matrix C(0, 0, 0, 0);
    Forn(i, 2){
      Forn(j, 2){
        Forn(k, 2){
          C.mat[i][j] += (A.mat[i][k] * B.mat[k][j]) % mod;
        }
      }
    }
    return C;
  }
};

matrix fpow(matrix x, lli y){
  matrix r = x;
  while( y > 0 ){
    if( y & 1 ){
      r = r * x;
    }
    x = x * x;
    y >>= 1;
  }
  return r;
}

lli fib(lli a, lli b, lli n, lli m){
  mod = pow(10ll, m);
  // debug(mod);
  matrix fibonacci = matrix(1, 1, 1, 0);
  matrix R = fpow(fibonacci, n - 1);
  return (a * R.mat[1][1] % mod + b * R.mat[1][0] % mod) % mod;
}

int main(){ _
  int q;
  cin >> q;
  Forn(i, q){
    lli a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << fib(a, b, n, m) << '\n';
  }
  return 0;
}
