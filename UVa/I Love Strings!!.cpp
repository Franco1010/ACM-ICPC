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

const int N = 1005;
const int S = 1005;
const int T = 2 * N * S;

string alpha;

struct aho_corasick{
  map<char, int> trie[T];
  vector<int> who[T];
  int link[T];

  int new_node = 0;

  void insert(string &s, int id, int x = 0){
    Forn(i, size(s)){
      if( !trie[x].count(s[i]) ){
        trie[x][s[i]] = ++new_node;
      }
      x = trie[x][s[i]];
    }
    who[x].pb(id);
  }

  int suffix(int x, char c){
    while( x && !trie[x][c] ){
      x = link[x];
    }
    return trie[x][c];
  }

  void build_links(){
    queue<int> q;
    q.push(0);
    while( !q.empty() ){
      int x = q.front();
      q.pop();
      for(char c: alpha){
        int y = trie[x][c];
        if( y == 0 ){
          continue;
        }
        link[y] = x ? suffix(link[x], c): 0;
        who[y].insert(who[y].end(), all(who[link[y]]));
        q.push(y);
      }
    }
  }

  vector<int> match(string &s, int x = 0){
    vector<int> ans;
    Forn(i, size(s)){
      x = suffix(x, s[i]);
      ans.insert(ans.end(), all(who[x]));
    }
    return ans;
  }

  void clear(){
    Forn(x, new_node + 1){
      trie[x].clear();
      who[x].clear();
      link[x] = 0;
    }
    new_node = 0;
  }
};

aho_corasick aho;
string s, q;
int n;

int main(){ _
  Forn(c, 256){
    if( isalpha(char(c)) ){
      alpha.pb(char(c));
    }
  }
  int tt;
  cin >> tt;
  while( tt-- ){
    aho.clear();
    cin >> s;
    cin >> n;
    Forn(i, n){
      cin >> q;
      aho.insert(q, i);
    }
    aho.build_links();
    vector<int> ans = aho.match(s);
    string is_sub(n, 'n');
    Forn(i, size(ans)){
      is_sub[ans[i]] = 'y';
    }
    Forn(i, n){
      cout << is_sub[i] << '\n';
    }
  }
  return 0;
}
