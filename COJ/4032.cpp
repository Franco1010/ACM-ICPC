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

vector<int>data;
ll n;
bool bsearch(int target){
  int left = 0;
  int right = n - 1;
  while (left < right){
    int mid = floor((left + right) / 2);
    if (data[mid] < target) left = mid + 1;
    else right = mid;
  }
  return (data[left] == target);
}

int main(){ _
  ll a,cont=0;
  cin>>n;
  data.resize(n);
  Forn(i,n){
    cin>>data[i];
  }
  set<int>s;
  Forn(i,n){
    if(bsearch(data[i])){
      s.insert(data[i]);
    }
  }
  //cout<<cont<<ENDL;
  cout<<sz(s)<<ENDL;
  for(int i: s)cout<<i<<ENDL;
  return 0;
}
