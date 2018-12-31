//https://codeforces.com/contest/1095/problem/C
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

const double pi = acos(-1);
const double eps = 1e6 - 9;
const lli mod = 1e9 + 7;
const lli inf = (1ll << 60);


vector<lli> pots;
pair<lli,lli> decom(lli n){
  pair<lli,lli>aux;
  aux.fst = pots[upper(all(pots), n) - pots.begin() - 1];
  aux.snd = n - aux.fst;
  return aux;
}

int main(){ _
  lli n, k, a, b, cur = 1;
  cin >> n >> k;
  for(int i = 1;i <= n; i*=2) pots.pb(i);
  map<lli,int> res;
  res[n] = 1;
  if(k > n) {
    cout << "NO\n";
    return 0;
  }
  if(k == 1){
    if( binary_search(all(pots), n)) cout << "YES\n" << n << ENDL;
    else cout << "NO\n";
    return 0;
  }
  while(cur < k){
    lli elem = 0;
    for(auto i = res.begin(); i != res.end(); i++){
      if(i->snd and !binary_search(all(pots),i->fst)){
        elem = i->fst;
        break;
      }
    }
    if(elem == 0){
      for(auto i = res.rbegin(); i != res.rend(); i++){
        if(i->snd){
          elem = i->fst;
          break;
        }
      }
    }
    if(elem%2 == 1){
      res[elem]--;
      res[1]++;
      res[elem-1]++;
      cur++;
    }
    else if(binary_search(all(pots), elem)){
       res[elem]--;
       res[elem/2] += 2;
       cur++;
     }
    else{
      tie(a,b) = decom(elem);
      res[elem]--;
      res[a]++;
      res[b]++;
      cur++;
    }
  }
  for(auto i = res.begin(); i != res.end(); i++){
    if(i->snd){
      if(!binary_search(all(pots),i->fst)){
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for(auto i = res.begin(); i != res.end(); i++){
    Forn(k, i->snd) cout << i->fst << ' ';
  }cout << ENDL;
  return 0;
}
