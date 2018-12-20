//https://codeforces.com/contest/1084/problem/A
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = c > 0 ? a: b; a <= i && i <= b; i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define For1(i, n) For(i, 1, n, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define debug(x) cout << #x": " << x << '\n';

#define fst first
#define snd second
#define pb push_back
#define lower lower_bound
#define upper upper_bound
#define ENDL '\n'
using namespace std;

typedef long long lli;
typedef unsigned long long ulli;
typedef pair<int, int> ii;

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;
const lli inf = (1ll << 60);

int main(){ _
  lli n,aux,act,m=inf,res=0;
  cin>>n;
  vector<int>v(n);
  Forn(i,n){
    cin>>v[i];
    res+=i*v[i]*4;
  }
  cout<<res<<ENDL;
  return 0;
}
