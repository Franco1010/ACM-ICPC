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
const lli mod = 1e9 + 7;
const int inf = (1 << 30);
const int W = 2000005;
const int N = 505;
 
struct item{
  int value;
  int weight;
};
 
int dp[W];
item items[N];
int n, max_weight;
 
int main(){
  cin >> max_weight >> n;
  Forn(i, n){
    cin >> items[i].value >> items[i].weight;
  }
  Forn(i, n){
    Rof(weight, max_weight, items[i].weight, -1){
      dp[weight] = max(dp[weight], dp[weight - items[i].weight] + items[i].value);
    }
  }
  cout << dp[max_weight] << '\n';
  return 0;
}
