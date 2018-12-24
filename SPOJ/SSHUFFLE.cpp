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

const int N = 65;

int dp[N][N][N];
string a, b, c;

int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    cin >> a >> b >> c;
    a = " " + a;
    b = " " + b;
    c = " " + c;
    Forn(lenA, size(a)){
      Forn(lenB, size(b)){
        Forn(lenC, size(c)){
          dp[lenA][lenB][lenC] = lenC == 0 ? 1: 0;
          if( lenA + lenB < lenC || lenC == 0 ){
            continue;
          }
          int k = lenC;
          For1(i, lenA) if( a[i] == c[k] ){
            dp[lenA][lenB][lenC] += dp[i - 1][lenB][k - 1];
          }
          For1(j, lenB) if( b[j] == c[k] ){
            dp[lenA][lenB][lenC] += dp[lenA][j - 1][k - 1];
          }
        }
      }
    }
    cout << dp[size(a) - 1][size(b) - 1][size(c) - 1] << '\n';
  }
  return 0;
}
