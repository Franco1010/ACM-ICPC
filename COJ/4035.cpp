//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define eps 1e-6
#define mod 1e9 + 7

#define _ ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout.precision(15);
#define For(it, a, b, inc) for(int it = (a); (a) <= it && it <= (b); it += inc)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
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
vector<ll>num;

void pre(string &s,int i){
  if(s.back()!=0)num.pb(stoll(s));
  if(sz(s)<10){
    if(i>0){
      s+=char(i-1+'0');
      pre(s,i-1);
      s.pop_back();
    }
    if(i<9){
      s+=char(i+1+'0');
      pre(s,i+1);
      s.pop_back();
    }
  }
}
int main(){ _
  ll n,aux,b;
  Forn(i,10){
    string s="";
    s+=char(i+'0');
    pre(s,i);
  }
  sort(all(num));
  //Forn(i,30)cout<<num[i]<<ENDL;
  cin>>n;
  while(n--){
    cin>>aux;
    b = upper(num,aux);
    //dprint(b);
    if(num[b]==aux)cout<<num[b+1]<<ENDL;
    else cout<<num[b]<<ENDL;
  }
  return 0;
}
