//touch {a..m}.in; tee {a..m}.cpp < template.cpp
//include </Users/francoarielramirezvilla/stdc++.h>
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
    cout<<fixed<<setprecision(1);
    ll c;
    double cc;
    vector<ll>v;
    while(cin>>c,c!=0){
      v.resize(c);
      forn(i,c){
        cin>>v[i];
      }
      sort(v.begin(),v.end());
      if(c%2!=0) cout<<double(v[c/2])<<ENDL;
      else cout<<double(v[c/2-1]+v[c/2])/2<<ENDL;
    }
    return 0;
}
