//https://codeforces.com/contest/1091/problem/B
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i += c)
#define Rof(i, a, b, c) for(int i = a; i >= b; i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define For1(i, n) For(i, 1, n, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
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
const lli llinf = (1ll << 60);
const lli inf = (1ll << 60);

int main(){ _
  lli n;
  cin >> n;
  vector<ii> coo(n);
  vector<ii> clue(n);
  Forn(i, n) cin >> coo[i].fst >> coo[i].snd;
  Forn(i, n) cin >> clue[i].fst >> clue[i].snd;
  sort(all(coo));
  sort(clue.rbegin(), clue.rend());
  cout << coo[0].fst + clue[0].fst << ' ' << coo[0].snd + clue[0].snd << ENDL;
  return 0;
}
