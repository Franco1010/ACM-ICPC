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
const int N = 105;

lli dp[N][N];
int done[N][N];
int timer = 0;
vector<lli> numbers;
string symbols;
string seq;

lli operation(char op, lli x, lli y){
  return op == '+' ? x + y: x * y;
}

lli calc_max(int l, int r){
  if( l == r ){
    return numbers[l];
  }
  if( l + 1 == r ){
    return operation(symbols[l], numbers[l], numbers[r]);
  }
  lli &ans = dp[l][r];
  if( done[l][r] != timer ){
    done[l][r] = timer;
    ans = 0;
    For(k, l, r - 1, +1){
      ans = max(ans, operation(symbols[k], calc_max(l, k), calc_max(k + 1, r)));
    }
  }
  return ans;
}

lli calc_min(int l, int r){
  if( l == r ){
    return numbers[l];
  }
  if( l + 1 == r ){
    return operation(symbols[l], numbers[l], numbers[r]);
  }
  lli &ans = dp[l][r];
  if( done[l][r] != timer ){
    done[l][r] = timer;
    ans = inf;
    For(k, l, r - 1, +1){
      ans = min(ans, operation(symbols[k], calc_min(l, k), calc_min(k + 1, r)));
    }
  }
  return ans;
}

int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    numbers = vector<lli>();
    symbols = "";
    cin >> seq;
    seq.pb('+');
    lli x = 0;
    Forn(i, size(seq)){
      if( seq[i] == '+' || seq[i] == '*' ){
        numbers.pb(x);
        symbols.pb(seq[i]);
        x = 0;
      }else{
        x = x * 10 + (seq[i] - '0');
      }
    }
    ++timer;
    lli mx = calc_max(0, size(numbers) - 1);
    ++timer;
    lli mn = calc_min(0, size(numbers) - 1);
    cout << mx << ' ' << mn << '\n';
  }
  return 0;
}
