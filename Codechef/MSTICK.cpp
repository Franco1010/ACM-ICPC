//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1e5+1
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
#define toCharA(i) (char)(i + 'A')
#define toChara(i) (char)(i + 'a')
#define toChar0(i) (char)(i + '0')

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int N = 1e5 + 5;
const int Log = 16 + 1;
ll lg[N];
ll a[N];
ll n;

ll s1[N][Log];
ll s2[N][Log];

class sparce_table{
public:
  //int sp[N][Log];
  int unite1(int x, int y){
    return min(x,y);
  }
  int unite2(int x, int y){
    return max(x,y);
  }
  void build(){
    for(int i = 0; i < n; i++){
      s1[i][0] = a[i];
      s2[i][0] = a[i];
    }
    for(int k = 1; k < Log; k++){
      int pk = k - 1;
      for(int i = 0; i + (1 << k) <= n; i++){
        s1[i][k] = unite1(s1[i][k - 1], s1[i + (1 << pk)][k - 1]);
        s2[i][k] = unite2(s2[i][k - 1], s2[i + (1 << pk)][k - 1]);
      }
    }
  }
  int query1(int ll, int rr){
    int length = rr - ll + 1;
    int k = lg[length];
    return unite1(s1[ll][k], s1[rr - (1 << k) + 1][k] );
  }
  int query2(int ll, int rr){
    int length = rr - ll + 1;
    int k = lg[length];
    return unite2(s2[ll][k], s2[rr - (1 << k) + 1][k] );
  }

};


void process_all_logs(){
  lg[1] = 0;
  for(int i = 2; i < N; i++){
    lg[i] = lg[i >> 1] + 1;
  }
}

int main() { _
  cout<<fixed<<setprecision(1);
  process_all_logs();
  sparce_table st;
  ll q,l,r;
  double m,ans,aux;
  cin>>n;
  forn(i,n)cin>>a[i];
  st.build();
  cin>>q;
  while(q--){
    cin>>l>>r;
    ans=0;
    m=st.query1(l,r);
    // dprint(st.query1(l,r));
    // dprint(st.query2(0,l-1));
    // dprint(st.query2(r+1,n-1));
    if(l>0)ans = max(ans,m+st.query2(0,l-1));
    if(r<n-1)ans = max(ans,m+st.query2(r+1,n-1));
    aux = st.query2(l,r);
    aux = m + (aux - m)/2;
    ans = max(ans,aux);
    cout<<ans<<ENDL;
  }
  return 0;
}
