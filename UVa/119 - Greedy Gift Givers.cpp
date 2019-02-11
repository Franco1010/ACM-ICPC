#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
const double eps = 1e-9;
const lli mod = 1e9 + 7;
const lli llinf = (1ll << 60);
//const int inf = (1 << 30);

int main(){ _
  lli n, m, money;
  string s, ss;
  cin >> n;
  while(true){
    map<string, int> mp;
    vector<string> ord;
    Forn(i, n){
      cin >> s;
      mp[s] = 0;
      ord.pb(s);
    }
    Forn(i, n){
      cin >> s >> money >> m;
      if(m == 0) {
        continue;
      }
      money /= m;
      mp[s] -= money*m;
      Forn(j, m){
        cin >> ss;
        mp[ss] += money;
      }
    }
    for(string i:ord){
      cout << i << ' ' << mp[i] << ENDL;
    }

    if(cin>>n) cout<<ENDL;
    else break;
  }
  return 0;
}
