//https://codeforces.com/contest/514/problem/C
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

const int T = 6.5e5 + 5;
const int Alpha = 26;

class trie{
private:
  struct node{
    bool flag;
    int child[Alpha];

    node(){
      flag = false;
      memset(child, -1, sizeof(child));
    }
  };

  node t[T];
  int new_node;

  void insert(int x, string &s){
    for(int i = 0; i < size(s); i++){
      int k = s[i] - 'a';
      if( t[x].child[k] == -1 ){
        t[x].child[k] = ++new_node;
      }
      x = t[x].child[k];
    }
    t[x].flag = true;
  }

  bool find(int x, int i, string &s, bool different){
    if( x == -1 ){
      return false;
    }
    if( i == size(s) ){
      return t[x].flag && different;
    }
    int k = s[i] - 'a';
    bool exists = false;
    if( different ){
      exists |= find(t[x].child[k], i + 1, s, different);
    }else{
      for(int nk = 0; nk < Alpha && !exists; nk++){
        exists |= find(t[x].child[nk], i + 1, s, k == nk ? different: true);
      }
    }
    return exists;
  }

public:
  void build(){
    new_node = 0;
  }

  void insert(string &s){
    insert(0, s);
  }

  bool find(string &s){
    return find(0, 0, s, false);
  }
};

trie t;
int n, m;

int main(){ _
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    t.insert(s);
  }
  for(int i = 0; i < m; i++){
    string s;
    cin >> s;
    cout << (t.find(s) ? "YES": "NO") << '\n';
  }
  return 0;
}
