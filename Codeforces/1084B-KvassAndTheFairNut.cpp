//https://codeforces.com/contest/1084/problem/B
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = c > 0 ? a: b; a <= i && i <= b; i += c)
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
const lli mod = 1e9 + 7;
const int inf = (1 << 30);
const int N = 1e3 + 5;

lli x[N], sum;
int n;

bool corta(lli height){
  lli sum2 = 0;
  Forn(i, n){
    if( x[i] >= height ) sum2 += x[i] - height;
    else return false;
  }
  return sum2 >= sum;
}

int main(){ _
  cin >> n >> sum;
  lli cnt = 0;
  Forn(i, n){
    cin >> x[i];
    cnt += x[i];
  }
  if( cnt < sum ){
    cout << "-1\n";
    return 0;
  }
  lli low = 0, high = *max_element(x, x + n);
  while( low + 1 < high ){
    lli mid = (low + high) / 2;
    if( corta(mid) ){
      low = mid;
    }else{
      high = mid;
    }
  }
  if( corta(high) ){
    cout << high << '\n';
  }else if( corta(low) ){
    cout << low << '\n';
  }else{
    cout << "-1\n";
  }
  return 0;
}
