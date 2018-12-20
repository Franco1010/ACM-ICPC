//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define eps 1e-6
#define mod int(1e9 + 7)

#define _ ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout.precision(15);
#define For(it, a, b, inc) for(int it = (a); (a) <= it && it <= (b); it += inc)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dforn(it, n) for(int i = n - 1; i >= 0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define lower(x, y) (lower_bound(all(x), y) - x.begin())
#define upper(x, y) (upper_bound(all(x), y) - x.begin())
#define ENDL '\n'
template <typename T> T mul(T x, T y){ return (x % mod * y % mod) % mod;}
// x * y % mod
template <typename T> T add(T x, T y){ return (x % mod + y % mod + mod) % mod;}
// (x (+,-) y + mod)% mod

typedef long long ll;
typedef pair<int, int> ii;

int main(){ _
  ll n,sum,aux,num,b;
  cin>>b;
  cin>>n;
  vector<int>v(n);
  sum=0;
  Forn(i,n){
    cin>>num;
    sum+=num;
    v[i]=num;
  }
  if(b>sum){
    cout<<1<<ENDL;
    return 0;
  }
  sort(v.rbegin(),v.rend());
  //Forn(i,n)cout<<v[i]<<' ';cout<<ENDL;
  aux=b;
  sum+=b;
  Forn(i,n){
    aux+=v[i];
    // dprint(aux);
    // dprint(sum-aux);
    if(aux>sum-aux){
      cout<<i+2<<ENDL;
      break;
    }
  }
  return 0;
}
