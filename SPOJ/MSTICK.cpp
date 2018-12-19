//https://www.spoj.com/problems/MSTICK/
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

const int N = 5005;

struct stick{
  int length = 0;
  int weight = 0;
};

stick sticks[N];
stick dp[N];
int n, m;

int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    cin >> n;
    For1(i, n){
      cin >> sticks[i].length >> sticks[i].weight;
    }
    sort(sticks + 1, sticks + n + 1, [=](stick a, stick b){
      if( a.length == b.length ){
        return a.weight < b.weight;
      }
      return a.length < b.length;
    });
    m = 0;
    dp[0] = sticks[0];
    For1(i, n){
      int low = 1, high = m;
      while( low <= high ){
        int mid = (low + high) / 2;
        if( !( dp[mid].length <= sticks[i].length && dp[mid].weight <= sticks[i].weight ) ){
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }
      dp[low] = sticks[i];
      m = max(m, low);
    }
    cout << m << '\n';
  }
  return 0;
}
