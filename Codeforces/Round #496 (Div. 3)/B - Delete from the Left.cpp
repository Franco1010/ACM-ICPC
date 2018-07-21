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

int main() {
    ios::sync_with_stdio(0);
    string a,b;
    ll t,c=0;
    cin>>a>>b;
    t=max(sz(a),sz(b));
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    forn(i,t){
      if(a[i]==b[i])c++;
      else break;
    }
    cout<<sz(a)+sz(b)-(c)*2<<ENDL;
    return 0;
}
