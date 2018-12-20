//https://codeforces.com/contest/1029/problem/A
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000000000LL
#define MOD 1000000007

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define ENDL '\n'

#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')
#define toCharA(i) (char)(i + 'a')
#define toChara(i) (char)(i + 'A')
#define toChar0(i) (char)(i + '0')

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN=100100;
ll n,k,l,cont,ini;
string s,res;

int main() { _
  cin>>n>>k>>s;
  l=sz(s);
  bool agr;
  res="";
  ini=-1;
  forr(i,1,l){
    agr=true;
    forn(j,l){
      if(i+j<l && s[j]!=s[i+j])agr=false;
    }
    if(agr){
      ini=i;
      break;
    }
  }
  //cout<<ini<<ENDL;
  if(ini==-1)ini=s.size();
  forn(i,k){
    res+=s.substr(0,ini);
  }
  res+=s.substr(ini,sz(s)-ini);
  cout<<res<<ENDL;
  return 0;
}
