//https://codeforces.com/contest/1008/problem/A
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
    string s;
    cin>>s;
    ll l=sz(s);
    forr(i,0,l-1){
      if(!isv(s[i])){
        if(s[i]=='n')continue;
        if(isv(s[i+1])) i++;
        else {
          cout<<"NO"<<ENDL;
          return 0;
        }
      }
    }
    if(s[l-1]=='n' || isv(s[l-1])) cout<<"YES"<<ENDL;
    else cout<<"NO"<<ENDL;
    return 0;
}
