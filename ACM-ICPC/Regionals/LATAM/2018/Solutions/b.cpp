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
  lli n,s;
  cin>>n;
  vector<int>v(n*2+5),in(n);
  v[0]=s=0;
  Forn(i,n){
    cin>>in[i];
    s+=in[i];
    v[i+1]=v[i]+in[i];
  }
  For(i,n+1,n*2,1){
    v[i]=v[i-1]+in[i-n-1];
  }
  v.erase(v.begin());
  if(s%2==1){
    cout<<"N"<<ENDL;
    return 0;
  }
  s/=2;
  vector<ii>pares;
  Forn(i,2*n){
    //debug(v[i]+s);
    if(binary_search(v.begin()+i+1,v.end(),v[i]+s)){
      pares.pb({v[i],v[i]+s});
    }
  }
  For(i,1,sz(pares),1){
    //cout<<pares[i].fst<<' '<<pares[i].snd<<ENDL;
    if(pares[i].fst < pares[i-1].snd and pares[i].snd > pares[i-1].snd){
      cout<<"Y"<<ENDL;
      return 0;
    }
  }
  cout<<"N"<<ENDL;
  return 0;
}
