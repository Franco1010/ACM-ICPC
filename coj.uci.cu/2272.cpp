#include <iostream>
#include <vector>
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
using namespace std;
vector<bool>p(1000000,true);
vector<long long int>primos;
void criba(){
    long long j;
    p[0]=p[1]=false;
    for (long long int i=2; i<1000000; i++) {
        if (p[i]) {
            for (j=i+i; j<1000000; j+=i) {
                p[j]=false;
            }
        }
    }
    for (j=0; j<1000000; j++) {
        if (p[j]) {
            primos.push_back(j);
        }
    }
}
bool isP(long long int x){
    for (long long int i=0; i<primos.size(); i++) {
        if (x%primos[i]==0) {
            return false;
        }
    }
    return true;
}
int main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    long long int c,num,x;
    vector<long long int>::iterator it;
    criba();
    cin>>c;
    while (c--) {
        cin>>num;
        if (num<1e6) {
            it= lower_bound(primos.begin(), primos.end(), num);
            x=(primos[it-primos.begin()]);
            cout<<x<<'\n';
        }else{
            if (isP(num)) {
                cout<<num<<'\n';
            }else{
                while (!isP(++num));
                cout<<num<<'\n';
            }
            
        }
    }
    return 0;
}
