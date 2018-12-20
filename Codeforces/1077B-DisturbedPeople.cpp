//https://codeforces.com/contest/1077/problem/B
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (c) > 0 ? (a): (b); (a) <= i && i <= (b); i += c)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); ++i)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define debug(x) cout << #x": " << x << '\n';
#define lower(x, y) (lower_bound(all(x), y) - (x).begin())
#define upper(x, y) (upper_bound(all(x), y) - (x).begin())
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;


int main(){ _
  lli n,res=0;
  cin>>n;
  vector<int>v(n);
  Forn(i,n)cin>>v[i];
  For(i,1,n-2,1){
    if(v[i]==0 and v[i-1]==1 and v[i+1]==1){
      ++res;
      v[i+1]=0;
    }
  }
  cout<<res<<ENDL;
  return 0;
}
