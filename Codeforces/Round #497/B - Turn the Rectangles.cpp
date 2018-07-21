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

bool isv(char x){
  if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')return true;
  return false;
}
int main() {
    ios::sync_with_stdio(0);
    ll c,a,b,act;
    cin>>c;
    cin>>a>>b;
    act=max(a,b);
    --c;
    while(c--){
      cin>>a>>b;
      if(a<=act&&b<=act)act=max(a,b);
      else if(a<=act) act=a;
      else if(b<=act) act=b;
      else {
        cout<<"NO"<<ENDL;
        return 0;
      }
    }
    cout<<"YES"<<ENDL;
    return 0;
}
