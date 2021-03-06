#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define debug(x) cerr << #x": " << x << '\n';

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

const int N = 2e6 + 5;

pair<lli, lli> phi[N];
bool is_prime[N];
lli depthphi[N];
lli dp[N];

void build_phi(){
  Forn(i, N){
    is_prime[i] = true;
    phi[i] = {1, 1};
  }
  For(i, 2, N - 1, +2){
    is_prime[i] = (i == 2 ? true: false);
    phi[i].fst *= 1;
    phi[i].snd *= 2;
  }
  For(i, 3, N - 1, +2){
    if( is_prime[i] ){
      For(j, i, N - 1, +i){
        is_prime[j] = (j == i ? true: false);
        phi[j].fst *= i - 1;
        phi[j].snd *= i;
      }
    }
  }
}

int main(){ _
  build_phi();
  depthphi[1] = dp[1] = 0;
  For(i, 2, N - 1, +1){
    int p = i * phi[i].fst / phi[i].snd;
    depthphi[i] = depthphi[p] + 1;
    dp[i] = dp[i - 1] + depthphi[i];
  }
  lli q, l, r;
  cin >> q;
  Forn(i, q){
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << '\n';
  }
  return 0;
}
