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
#define dprint(v) cout << #v"=" << v << endl
#define ENDL '\n'

struct porP{
  ll num;
  ll pos;
  bool operator<(const porP &t) const
  {
      return pos < t.pos;
  }
};
struct porN{
  ll num;
  ll pos;
  bool operator<(const porN &t) const
  {
      return num < t.num;
  }
};
int main() {
    ios::sync_with_stdio(0);
    ll c,p;
    porN pn;
    porP pp;
    cin>>c>>p;
    vector<ll>v(c);
    vector<porN>nn;
    forn(i,c){
      cin>>v[i];
      pn.num=v[i];
      pn.pos=i;
      nn.pb(pn);
    }
    sort(nn.rbegin(),nn.rend());
    vector<porP>ppp;
    ll sum=0;
    forn(i,p){
      pp.num=nn[i].num;
      pp.pos=nn[i].pos;
      ppp.pb(pp);
      sum+=pp.num;
    }
    sort(ppp.begin(),ppp.end());
    ppp[p-1].pos=c-1;
    cout<<sum<<ENDL;
    cout<<ppp[0].pos+1<<' ';
    forr(i,1,p){
      cout<<ppp[i].pos-ppp[i-1].pos<<' ';
    }
    cout<<ENDL;
    return 0;
}
