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
    ll c,num,ant=1;
    vector<ll>res;
    cin>>c;
    while(c--){
      cin>>num;
      if(num==1){
        res.pb(ant);
        ant=1;
      }else ++ant;
    }res.pb(ant);
    cout<<sz(res)-1<<ENDL;
    forr(i,1,sz(res)){
      cout<<res[i]<<' ';
    }cout<<ENDL;
    return 0;
}
