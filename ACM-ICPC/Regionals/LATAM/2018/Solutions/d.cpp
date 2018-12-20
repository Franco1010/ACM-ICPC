//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define empty(x) (x).empty()
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define debug(x) cout << #x"=" << x << endl
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
  lli n;
  string aux,res;
  set<string>s;
  bool desp,mas;
  cin>>n;
  while(n--){
    cin>>aux;
    res="";
    desp=false;
    mas=false;
    Forn(i,sz(aux)){
      if(aux[i]=='@'){
        desp=true;
        mas=false;
        res.pb(aux[i]);
        continue;
      }
      if(mas)continue;
      if(aux[i]=='+'){
        mas=true;
        continue;
      }
      if(!desp and aux[i]!='.')res.pb(aux[i]);
      if(desp)res.pb(aux[i]);
    }
    s.insert(res);

  }
  //for(auto i:s)cout<<i<<ENDL;
  cout<<sz(s)<<ENDL;
  return 0;
}
