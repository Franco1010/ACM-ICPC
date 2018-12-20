//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define eps 1e-6
#define mod 1e9 + 7

#define _ ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout.precision(15);
#define For(it, a, b, inc) for(int it = (a); (a) <= it && it <= (b); it += inc)
#define Forn(i, n) For(i, 0, n - 1, 1)
#define Forall(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl
#define lower(x, y) (lower_bound(all(x), y) - x.begin())
#define upper(x, y) (upper_bound(all(x), y) - x.begin())
#define ENDL '\n'
template <typename T> T mul(T x, T y){ return (x % mod * y % mod) % mod;}
// x * y % mod
template <typename T> T add(T x, T y){ return (x % mod + y % mod + mod) % mod;}
// (x (+,-) y + mod)% mod

typedef long long ll;
typedef pair<int, int> ii;

string codes[10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

class Trie{
  struct Node{
    int child[26];
    bool flag;

    Node(){
      flag=false;
      fill(child,child+26,-1);
    }
  };

  Node t[11*2000];
  int newNode;

  void insert(string &s,int x){
    Forn(i,sz(s)){
      if(t[x].child[s[i]-'A']==-1) t[x].child[s[i]-'A']=++newNode;
      x = t[x].child[s[i]-'A'];
    }
    t[x].flag = true;
  }

  bool find(int x, int i, string &s, string& ans){
    if(x==-1) return false;
    if(i==sz(s)) return t[x].flag;
    for(char c : codes[s[i]-'0']){
      ans += c;
      if(find(t[x].child[c-'A'],i+1,s,ans)){
        return true;
      }
      ans.pop_back();
    }
    return false;
  }

public:

  void build(){
    newNode=0;
  }
  void insert(string s){
    insert(s,0);
  }
  string find(string s){
    string res="";
    if(find(0,0,s,res)){
      return res;
    }else return "no solution";
  }
};

int main(){ _
  ll n;
  string s;
  Trie trie;
  trie.build();
  cin>>n;
  Forn(i,n){
    cin>>s;
    trie.insert(s);
  }
  cin>>n;
  Forn(i,n){
    cin>>s;
    cout<<trie.find(s)<<ENDL;
  }
  return 0;
}
