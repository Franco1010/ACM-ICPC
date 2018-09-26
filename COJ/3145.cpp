#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1e5+1
#define MOD 1000000007

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define ENDL '\n'

#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')
#define toCharA(i) (char)(i + 'A')
#define toChara(i) (char)(i + 'a')
#define toChar0(i) (char)(i + '0')

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() { _
  ll n,q,aux,pos;
  cin>>n>>q;
  vector<ll>v(n+1,0);
  vector<ll>sum(n+1,0);
  forn(i,n){
    cin>>v[i+1];
    sum[i+1]=sum[i]+v[i+1];
  }
  sum[0]=-1;
  // forn(i,n+1)cout<<v[i]<<' ';cout<<ENDL;
  // forn(i,n+1)cout<<sum[i]<<' ';cout<<ENDL;
  forn(i,q){
    cin>>aux;
    pos=lower_bound(sum.begin(),sum.end(),aux+1)-sum.begin();
    // cout<<"aux: "<<aux<<' ';
    // cout<<"pos: "<<pos<<ENDL;
    // cout<<v[pos+1]<<ENDL;
    cout<<pos<<ENDL;
  }
  return 0;
}
