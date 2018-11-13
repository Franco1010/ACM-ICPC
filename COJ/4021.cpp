//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl
#define lower(x, y) (lower_bound(all(x), y) - (x).begin())
#define upper(x, y) (upper_bound(all(x), y) - (x).begin())
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;

int main(){ _
  lli t,n,k,lim,res;
  cin>>t;
  while(t--){
    cin>>n>>k;
    lim=res=-1;
    vector<lli>v(n);
    Forn(i,n){
      cin>>v[i];
      lim=max(lim,v[i]);
    }
    lli l=0,r=lim,m,aux;
    while(l<r-1){
      m=(l+r)/2;
      aux=0;
      Forn(i,n)aux+=v[i]/m;
      if(aux < k) r=m;
      else {
        l=m;
        res=max(res,m);
      }
    }
    cout<<res<<ENDL;
  }
  return 0;
}
