//https://codeforces.com/contest/1091/problem/C
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i += c)
#define Rof(i, a, b, c) for(int i = a; i >= b; i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define For1(i, n) For(i, 1, n, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
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

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;
const lli llinf = (1ll << 60);
const lli inf = (1ll << 60);

vector<lli> d;
map<lli,bool>mp, mp2;

void findDiv(lli n){
  lli root = sqrt(n);
  for(lli i = 1; i<=root; ++i){
    if(n%i == 0){
      if(n/i == i){
         if(!mp[i]) d.pb(i);
         mp[i] = true;
      }
      else {
        if(!mp[i]) d.pb(i);
        if(!mp[n/i]) d.pb(n/i);
        mp[i] = true;
        mp[n/i] = true;
      }
    }
  }
}
int main(){ _
  lli n, sum, aux;
  cin >> n;
  findDiv(n);
  vector<lli> res;
  for(lli i:d){
    sum = 0;
    aux = n/i;
    sum = aux;
    sum += ((aux*(aux-1))/2) * i;
    if(!mp2[sum]) res.pb(sum);
    mp2[sum] = true;
  }
  sort(all(res));
  for(lli i:res) cout << i << ' '; cout << ENDL;
  return 0;
}
