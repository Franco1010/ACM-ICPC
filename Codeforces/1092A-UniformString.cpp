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

int main(){ _
  lli t, n, k;
  cin >> t;
  while(t--){
    cin >> n >> k;
    char l = 'a';
    string aux = "";
    lli limit;
    while(sz(aux) < n){
      if(n/k + sz(aux) > n){
        limit = n - sz(aux);
      }else limit = n/k;
      //debug(limit);
      Forn(i, limit){
        aux += l;
      }
      l = min(int(l+1-'a'), int(k-1)) + 'a';
    }
    cout << aux << ENDL;
  }
  return 0;
}
