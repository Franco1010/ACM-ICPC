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
const int N = 25;

int suitcases[N];
int n;

int main(){ _
  int tt;
  cin >> tt;
  Forn(t, tt){
    cin >> n;
    stringstream ss;
    string input;
    getline(cin, input);
    ss << input;
    Forn(i, n){
      ss >> suitcases[i];
    }
    bool yes = false;
    Forn(mask, (1 << n)){
      int sum = 0;
      Forn(i, n){
        sum += ((mask >> i) & 1 ? 1: -1) * suitcases[i];
      }
      if( sum == 0 ){
        yes = true;
        break;
      }
    }
    cout << (yes ? "YES\n": "NO\n");
  }
  return 0;
}
