#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i += c)
#define Rof(i, a, b, c) for(int i = a; i >= b; i += c)
#define Forn(i, n) For(i, 0, n - 1, +1)
#define For1(i, n) For(i, 1, n, +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
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
const int inf = (1 << 30);
const int N = 205;
 
enum {fleft = 0, fright};
int dp[N][N][2];
int done[N][N][2];
int timer = 0;
char mat[N][N];
int n, m;
 
bool valid(int x, int y){
  return 0 <= x && x <= n && 0 <= y && y < m;
}
 
int calc(int x, int y, bool facing){
  if( x == n ){
    return 0;
  }
  int &ans = dp[x][y][facing];
  if( done[x][y][facing] != timer ){
    done[x][y][facing] = timer;
    int tree = mat[x][y] == 'T';
    ans = tree;
    if( facing == fright ){
      if( valid(x, y + 1) && mat[x][y + 1] != '#' ){
        ans = max(ans, calc(x, y + 1, fright) + tree);
      }
      if( valid(x + 1, y) && mat[x + 1][y] != '#' ){
        ans = max(ans, calc(x + 1, y, fleft) + tree);
      }
    }else{
      if( valid(x, y - 1) && mat[x][y - 1] != '#' ){
        ans = max(ans, calc(x, y - 1, fleft) + tree);
      }
      if( valid(x + 1, y) && mat[x + 1][y] != '#' ){
        ans = max(ans, calc(x + 1, y, fright) + tree);
      }
    }
  }
  return ans;
}
 
int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    cin >> n >> m;
    Forn(x, n){
      Forn(y, m){
        cin >> mat[x][y];
      }
    }
    fill_n(mat[n], m, '0');
    ++timer;
    cout << (mat[0][0] == '#' ? 0: calc(0, 0, fright)) << '\n';
  }
  return 0;
}
