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


bool mapa[1000000+5];
int main(){ _
  lli t,n,aux,cont;
  cin>>t;
  while(t--){
    cin>>n;
    Forn(i,n+5)mapa[i]=false;
    aux=cont=0;
    while(true){
      aux=(aux*10+1)%n;
      if(aux==0){
        cout<<cont+1<<ENDL;
        break;
      }
      if(mapa[aux]){
        cout<<-1<<ENDL;
        break;
      }
      mapa[aux]=true;
      ++cont;
    }
  }
  return 0;
}
