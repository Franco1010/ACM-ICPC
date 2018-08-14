//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include </Users/francoarielramirezvilla/stdc++.h>
//#include <bits/stdc++.h>
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
    ll n,m,aux,cont=1;
    while(cin>>n>>m){
      if(n==m && m==0)break;
      cout<<"CASE# "<<cont++<<":"<<ENDL;
      vector<ll>v(n);
      forn(i,n)cin>>v[i];
      sort(v.begin(),v.end());
      forn(i,m){
        cin>>aux;
        if(binary_search(v.begin(),v.end(),aux)){
          cout<<aux<<" found at "<<lower_bound(v.begin(),v.end(),aux)-v.begin()+1<<ENDL;
        }else cout<<aux<<" not found"<<ENDL;
      }
    }
    return 0;
}
