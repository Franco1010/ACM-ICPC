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
const int inf = 1e9 + 9;

int dp[N][N][N];
int done[N][N][N];
int timer = 0;
set<string> insignificant;
string abbreviation;
string significant;
int who[N];
string word;
int n;

void divide(){
  significant = "";
  abbreviation = "";
  stringstream ss;
  string tmp;
  ss << word;
  set<int> marks;
  while( ss >> tmp ){
    if( !insignificant.count(tmp) ){
      if( abbreviation.empty() ){
        abbreviation = tmp;
      }else{
        significant += tmp;
        marks.insert(size(significant));
      }
    }
  }
  who[0] = 0;
  For1(i, size(significant)){
    who[i] = who[i - 1];
    if( marks.count(i) ){
      who[i]++;
    }
  }
}

// {i-th of abbreviation, j-th significant words, using k-th significant words}
int calc(int i, int j, int k){
  //printf("i: %d, j: %d, k: %d\n", i, j, k);
  if( i == size(abbreviation) ){
    return k == who[size(significant) - 1];
  }
  if( j >= size(significant) ){
    return 0;
  }
  if(k >= who[size(significant) - 1]){
    return 0;
  }
  int &ans = dp[i][j][k];
  if( done[i][j][k] != timer ){
    done[i][j][k] = timer;
    ans = 0;
    For(nj, j, size(significant), +1){
      if( tolower(abbreviation[i]) == significant[j] ){
        ans += calc(i + 1, nj + 1, k + (who[nj] != who[j-1]));
      }
    }
  }
  return ans;
}

int main(){ _
  while( cin >> n, n != 0 ){
    insignificant = set<string>();
    Forn(i, n){
      string s;
      cin >> s;
      insignificant.insert(s);
    }
    getline(cin, word);
    while( getline(cin, word) && word != "LAST CASE" ){
      divide();
      debug(abbreviation);
      debug(significant);
      Forn(i, size(significant)){
        cout << who[i] << " ";
      }
      cout << '\n';

      ++timer;
      if( calc(0, 0, 0) == 0 ){
        cout << abbreviation << " is not a valid abbreviation\n";
      }else{
        cout << abbreviation << " can be formed in " << calc(0, 0, 0) << " ways\n";
      }
      puts("");
    }
  }
  return 0;
}
