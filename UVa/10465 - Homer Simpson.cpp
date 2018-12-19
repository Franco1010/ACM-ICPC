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

const int T = 10005;

int dp[T];
int n, m, maxT;

int main(){ _
  while( cin >> n >> m >> maxT ){
    dp[0] = 0;
    For1(t, maxT){
      dp[t] = -1;
      if( t - n >= 0 && dp[t - n] != -1 ){
        dp[t] = max(dp[t], dp[t - n] + 1);
      }
      if( t - m >= 0 && dp[t - m] != -1 ){
        dp[t] = max(dp[t], dp[t - m] + 1);
      }
    }
    int burguers = 0, beer = 0;
    while( maxT > 0 ){
      if( dp[maxT] == -1 ){
        beer++;
      }else{
        burguers = dp[maxT];
        break;
      }
      maxT--;
    }
    cout << burguers << " \n"[!beer];
    if( beer ){
      cout << beer << '\n';
    }
  }
  return 0;
}
