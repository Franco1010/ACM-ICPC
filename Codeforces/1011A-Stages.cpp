//https://codeforces.com/contest/1011/problem/A
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

ll n,k,res;
string s;
void recur(int posa, ll w, int aux){
  if(aux==k){
    //cout<<endl<<aux<<' '<<w<<endl;
    res=min(res,w);
    return;
  }
  forr(i,posa+1,n){
    if(s[i]>s[posa]+1){
      //cout<<s[i]<<' ';
      recur(i,w+(s[i]-'a')+1,aux+1);
    }
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin>>n>>k;
    cin>>s;
    sort(s.begin(),s.end());
    res=2600;
    forn(i,n)recur(i,(s[i]-'a')+1,1);
    if(res==2600)cout<<-1<<ENDL;
    else cout<<res<<ENDL;
    return 0;
}
