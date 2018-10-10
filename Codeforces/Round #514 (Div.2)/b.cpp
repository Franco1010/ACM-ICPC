//touch {a..m}.in; tee {a..m}.cpp < template.cpp
//#include </Users/francoarielramirezvilla/stdc++.h>
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

ll n,m;
vector<string>v,res;

void check(int i, int j){
  int ii,jj;
  bool bo;
  if(i+2<n and j+2<m){
    bo=true;
    ii=i+1;
    jj=j+1;
    forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0) and v[ii+x][jj+y]!='#'){bo=false;break;}
    if(bo)forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0))res[ii+x][jj+y]='#';
  }
  if(i+2<n and j-2>=0){
    bo=true;
    ii=i+1;
    jj=j-1;
    forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0) and v[ii+x][jj+y]!='#'){bo=false;break;}
    if(bo)forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0))res[ii+x][jj+y]='#';
  }
  if(i-2>=0 and j+2<m){
    bo=true;
    ii=i-1;
    jj=j+1;
    forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0) and v[ii+x][jj+y]!='#'){bo=false;break;}
    if(bo)forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0))res[ii+x][jj+y]='#';
  }
  if(i-2>=0 and j-2>=0){
    bo=true;
    ii=i-1;
    jj=j-1;
    forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0) and v[ii+x][jj+y]!='#'){bo=false;break;}
    if(bo)forr(x,-1,2)forr(y,-1,2)if(not(x==0 and y==0))res[ii+x][jj+y]='#';
  }
}

int main() {_
  cin>>n>>m;
  v.resize(n);
  res.resize(n);
  string base="";
  forn(i,m)base+=".";
  forn(i,n){
    cin>>v[i];
    res[i]=base;
  }
  forn(i,n){
    forn(j,m){
      if(v[i][j]=='#'){
        check(i,j);
      }
    }
  }
  forn(i,n){
    forn(j,m){
      if(v[i][j]!=res[i][j]){
        cout<<"NO"<<ENDL;
        return 0;
      }
    }
  }
  cout<<"YES"<<ENDL;
  return 0;
}
