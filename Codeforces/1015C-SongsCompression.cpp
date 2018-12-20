//https://codeforces.com/contest/1015/problem/C
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
#define ENDL '\n'

struct tres{
  ll a,b,d;
  bool operator<(const tres &t) const
  {
      return d < t.d;
  }
};
int main() {
    ios::sync_with_stdio(0);
    ll n,m,s,r,sum=0,pos,res=0;
    tres aux;
    cin>>n>>m;
    vector<tres>v(n);
    forn(i,n){
      cin>>aux.a>>aux.b;
      aux.d=abs(aux.a-aux.b);
      v[i]=aux;
      sum+=aux.a;
    }
    sort(v.rbegin(),v.rend());
    pos=0;
    while(sum>m && pos<n){
      if(v[pos].a>v[pos].b){
        sum-=v[pos++].d;
        ++res;
      }
    }
    if(sum>m)cout<<-1<<ENDL;
    else cout<<res<<ENDL;
    return 0;
}
