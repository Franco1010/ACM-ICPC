#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;
vector<long long int>primos;
long long l;
vector<bool> p(1000000,true);
void criba(){
    
    for (int i=2; i<1000000; i++) {
        if (p[i]) {
            for (int j=i+i; j<1000000; j+=i) {
                p[j]=false;
            }
        }
    }
    for (int i=2; i<1000000; i++) {
        if (p[i]) {
            primos.push_back(i);
        }
    }
}

bool isPrime(long long int x){
    if(x==1)return false;
    long int r= sqrt(x);
    if (x>1000000) {
        for (int i=0; i<l; i++) {
            if (primos[i]>r) {
                return true;
            }
            while (x%primos[i]==0) {
                return false;
            }
        }
    }else return p[x];
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    criba();
    l=primos.size();
    long long int c,a,b,i;
    cin>>c;
    while (c--) {
        cin>>a>>b;
        for (i=a;i<=b; i++) {
            if (isPrime(i)) {
                cout<<i<<'\n';
            }
        }cout<<'\n';
    }
    return 0;
}
