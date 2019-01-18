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

bool is_prime[N];
lli phi[N];
lli sum[N];

int main(){ _
  Forn(i, N){
    is_prime[i] = true;
    phi[i] = i;
  }
  is_prime[0] = is_prime[1] = false;
  For(i, 2, N - 1, +1){
    if( is_prime[i] ){
      For(j, i, N - 1, +i){
        is_prime[j] = (i == j);
        phi[j] /= i;
        phi[j] *= i - 1;
      }
    }
  }
  For1(i, N - 1){
    For(j, i + i, N - 1, +i){
      sum[j] += i * phi[j / i];
    }
    sum[i] += sum[i - 1];
  }
  int n;
  while( cin >> n, n != 0 ){
    cout << sum[n] << '\n';
  }
  return 0;
}
