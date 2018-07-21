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

int main() {
    ios::sync_with_stdio(0);
    ll c,res=21;
    cin>>c;
    vector<ll>v(c),dp1(c+1),dp2(c+1);
    forn(i,c)cin>>v[i];
    dp1[0]=dp2[c]=0;
    forn(i,c){
      dp1[i+1]=dp1[i]+v[i];
    }
    dforn(i,c){
      dp2[i]=dp2[i+1]+v[i];
    }
    reverse(dp2.begin(),dp2.end());
    forn(i,c){
      if(binary_search(dp2.begin(),dp2.end()-i,dp1[i])){
        res=dp1[i];
      }
    }
    cout<<res<<ENDL;
    return 0;
}
