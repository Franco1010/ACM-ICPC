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

const int N = 105;

vector<int> g[N];
unordered_set<int> cutpoints;
int tin[N];
int fup[N];
bool vis[N];
int timer;
int n;

void cutpoints_dfs(int u, int pr = -1){
  vis[u] = true;
  tin[u] = fup[u] = ++timer;
  int children = 0;
  for(int v: g[u]){
    if( v == pr ){
      continue;
    }
    if( !vis[v] ){
      cutpoints_dfs(v, u);
      ++children;
      fup[u] = min(fup[u], fup[v]);
      if( fup[v] >= tin[u] && pr != -1 ){
        cutpoints.insert(u);
      }
    }else{
      fup[u] = min(fup[u], tin[v]);
    }
  }
  if( pr == -1 && children > 1 ){
    cutpoints.insert(u);
  }
}

void find_cutpoints(){
  For1(u, n){
    vis[u] = false;
    tin[u] = -1;
    fup[u] = -1;
  }
  cutpoints = unordered_set<int>();
  For1(u, n){
    if( !vis[u] ){
      cutpoints_dfs(u);
    }
  }
}

int main(){ _
  while( cin >> n, n != 0 ){
    For1(u, n){
      g[u] = vector<int>();
    }
    string s;
    while( getline(cin, s), s != "0" ){
      stringstream ss(s);
      int u, v;
      ss >> u;
      while( ss >> v ){
        g[u].pb(v);
        g[v].pb(u);
      }
    }
    find_cutpoints();
    cout << size(cutpoints) << '\n';
  }
  return 0;
}
