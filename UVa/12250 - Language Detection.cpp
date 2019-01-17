// touch {a..l}.in; tee {a..l}.cpp < template.cpp
#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define sz(x) size(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
const double eps = 1e-9;
const lli mod = 1e9 + 7;
const lli llinf = (1ll << 60);
//const int inf = (1 << 30);

int main(){ _
  string s;
  lli cont = 1;
  while(cin >> s){
    if(s == "#") return 0;
    cout << "Case " << cont++ << ": ";
    if(s == "HELLO") cout << "ENGLISH" << ENDL;
    else if(s == "HOLA") cout << "SPANISH" << ENDL;
    else if(s == "HALLO") cout << "GERMAN" << ENDL;
    else if(s == "BONJOUR") cout << "FRENCH" << ENDL;
    else if(s == "CIAO") cout << "ITALIAN" << ENDL;
    else if(s == "ZDRAVSTVUJTE") cout << "RUSSIAN" << ENDL;
    else cout << "UNKNOWN" << ENDL;
  }
  return 0;
}
