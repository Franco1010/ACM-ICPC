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

const int W = 1e5 + 5;
const int N = 1005;

struct elephant{
  int weight;
  int iq;
  int id;

  elephant(int weight1, int iq1, int id1){
    weight = weight1, iq = iq1, id = id1;
  }

  elephant(){}
};

vector<elephant> elephants;
int dp[N];
int from[N];
int n;

bool sequence(elephant a, elephant b){
  return a.weight < b.weight && a.iq > b.iq;
}

void rebuild(int x){
  if( x == 0 ){
    return;
  }
  rebuild(from[x]);
  cout << elephants[x].id << '\n';
}

int main(){ _
  elephants.pb(elephant(0, W, 0));
  int weight, iq;
  while( cin >> weight >> iq ){
    elephants.pb(elephant(weight, iq, ++n));
  }
  sort(all(elephants), [=](elephant a, elephant b){
    if( a.weight == b.weight ){
      return a.iq > b.iq;
    }
    return a.weight < b.weight;
  });
  dp[0] = 0, from[0] = -1;
  int start = 0;
  For1(cur, n){
    dp[cur] = 1, from[cur] = -1;
    Rof(prev, cur - 1, 0, -1){
      if( sequence(elephants[prev], elephants[cur]) && dp[prev] + 1 >= dp[cur] ){
        dp[cur] = dp[prev] + 1;
        from[cur] = prev;
      }
    }
    if( dp[cur] >= dp[start] ){
      start = cur;
    }
  }
  cout << dp[start] << '\n';
  rebuild(start);
  return 0;
}
