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

const int N = 5005;

unordered_set<int> not_trusts[N];
int tin[N];
int lowlink[N];
vector< vector<int> > scc;
bool vis[N];
stack<int> slew;
int n, m;
lli cost;

void tarjan_dfs(int u, int pr = -1){
	static int timer = 0;
	lowlink[u] = tin[u] = ++timer;
	vis[u] = true;
	slew.push(u);
	For1(v, n){
    if( not_trusts[u].count(v) ){
      continue;
    }
		if( tin[v] == -1 ){
			tarjan_dfs(v, u);
		}
		if( vis[v] ){
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
	}
	if( lowlink[u] == tin[u] ){
		vector<int> component;
		while(true){
			int v = slew.top();
			slew.pop();
			vis[v] = false;
			component.pb(v);
			if( u == v ){
				break;
			}
		}
		scc.pb(component);
	}
}

void tarjan(){
	For1(u, n){
		tin[u] = -1;
		lowlink[u] = -1;
		vis[u] = false;
	}
  scc = vector< vector<int> >();
	For1(u, n){
		if( tin[u] == -1 ){
			tarjan_dfs(u);
		}
	}
}

int main(){ _
  while( cin >> n >> m ){
    For1(u, n){
      not_trusts[u] = unordered_set<int>();
    }
    Forn(id, m){
      int u, v;
      cin >> u >> v;
      not_trusts[u].insert(v);
    }
    cin >> cost;
    tarjan();
    cout << "hi\";
    cout << 1ll * size(scc) * cost << '\n';
  }
  return 0;
}
