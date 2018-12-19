#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i += c)
#define Rof(i, a, b, c) for(int i = a; i >= b; i += c)
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

const lli inf = (1ll << 60);
const int N = 5005;

enum {Flippy = 0, Fluffy};
lli dp[N][N];
bool done[N][N];
lli a[N];
lli b[N];
int n;

lli calc(int i, int j, bool turn){
  if( i > n || j > n ){
    return (turn == Fluffy ? inf: -inf);
  }
  if( i == n && j == n ){
    return 0;
  }
  lli &ans = dp[i][j];
  if( !done[i][j] ){
    done[i][j] = true;
    if( turn == Fluffy ){
      ans = max(calc(i + 1, j, !turn) + a[i],
                calc(i, j + 1, !turn) + b[j]);
    }else{
      ans = min(calc(i + 1, j, !turn) - a[i],
                calc(i, j + 1, !turn) - b[j]);
    }
  }
  return ans;
}

int main(){ _
  cin >> n;
  Forn(i, n){
    cin >> a[i];
  }
  Forn(i, n){
    cin >> b[i];
  }
  cout << calc(0, 0, Fluffy) << '\n';
  return 0;
}
