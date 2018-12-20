//https://codeforces.com/contest/1023/problem/C
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
    ll n,m,p=0,q=0,aux;
    string s="",res="";
    char x;
    vector<ll>a,b;
    cin>>n>>m;
    forn(i,n){
      cin>>x;
      if(x=='(')a.pb(i);
      else b.pb(i);
      s+=x;
    }
    //cout<<s<<ENDL;
    aux=n-m;
    while(aux--,aux>=0){
      s[a[p++]]='*';
      aux--;
      s[b[q++]]='*';
    }
    //cout<<s<<endl;
    forn(i,n){
      if(s[i]!='*'){
        res+=s[i];
      }
    }
    cout<<res<<ENDL;
    return 0;
}
