#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
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

const int N = 155;

// {ith letter of abbreviation, jth significant word, k letters of significant[j] added}
int dp[N][N][N];
int done[N][N][N];
int timer = 0;
set<string> insignificants;
vector<string> significants;
string abbreviation;
string tmp;
int n;

int calc(int i, int j, int k){
  if( i == size(abbreviation) ){
    return j == size(significants);
  }
  if( j == size(significants) || k == size(significants[j]) ){
    return 0;
  }
  int &ans = dp[i][j][k];
  if( done[i][j][k] != timer ){
    done[i][j][k] = timer;
    ans = 0;
    For(nk, k, size(significants[j]) - 1, +1){
      if( tolower(abbreviation[i]) == significants[j][nk] ){
        ans += calc(i + 1, j + 1, 0); // Next word
        ans += calc(i + 1, j, nk + 1); // Same word
      }
    }
  }
  return ans;
}

int main(){ _
  while( cin >> n, n != 0 ){
    insignificants = set<string>();
    Forn(i, n){
      cin >> tmp;
      insignificants.insert(tmp);
    }
    getline(cin, tmp);
    while( getline(cin, tmp) && tmp != "LAST CASE" ){
      stringstream ss;
      ss << tmp;
      ss >> abbreviation;
      significants = vector<string>();
      while( ss >> tmp ){
        if( !insignificants.count(tmp) ){
          significants.pb(tmp);
        }
      }
      ++timer;
      if( calc(0, 0, 0) == 0 ){
        cout << abbreviation << " is not a valid abbreviation\n";
      }else{
        cout << abbreviation << " can be formed in " << calc(0, 0, 0) << " ways\n";
      }
    }
  }
  return 0;
}
