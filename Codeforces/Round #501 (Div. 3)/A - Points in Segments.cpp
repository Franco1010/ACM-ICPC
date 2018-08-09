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

bool tramo[101];
int main() {
    ios::sync_with_stdio(0);
    ll n,m,l,r,res=0,b,pos,tot=0;
    cin>>n>>m;
    forn(i,n){
      cin>>l>>r;
      forr(j,l-1,r)tramo[j]=true;
      //if(l==r)--tot;
      //else tot-=(r-l);
    }
    vector<int>v;
    forn(i,m){
      if(!tramo[i]){
        ++tot;
        v.pb(i+1);
      }
    }
    cout<<tot<<ENDL;
    for(int i:v)cout<<i<<' ';
    cout<<ENDL;
    return 0;
}
