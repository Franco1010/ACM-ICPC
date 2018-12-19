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

const int N = 1005;

int dp[N][N];
string a, b;

int main(){ _
  while( true ){
    getline(cin, a);
    getline(cin, b);
    if( a.empty() ) break;
    a = " " + a;
    b = " " + b;
    For1(i, size(a) - 1){
      For1(j, size(b) - 1){
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if( a[i] == b[j] ){
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }
    cout << dp[size(a) - 1][size(b) - 1] << '\n';
  }
  return 0;
}
