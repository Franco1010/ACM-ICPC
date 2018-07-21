#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;
long long l;
vector<bool> p(1000000,true);
vector<long long int> primos;
void criba(){
    p[0]=false;p[1]=false;
    long long int cont=0;
    for (int i=2; i<1000000; i++) {
        if (p[i]) {
            for (int j=i+i; j<1000000; j+=i) {
                p[j]=false;
            }
        }
    }
    for (int i=0; i<1000000; i++) {
        if (p[i]) {
            primos.push_back(i);
        }
        //pp.push_back(cont);
    }
}
/*
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
}*/
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    criba();
    vector<long long int>::iterator l1,l2;
    long long int c,a,b,h,g;
    cin>>c;
    while (c--) {
        cin>>a;
        if (p[a]) {
            cout<<a<<' '<<a<<'\n';
            continue;
        }
        l1=lower_bound(primos.begin(), primos.end(), a);
        l2=upper_bound(primos.begin(), primos.end(), a);
        h=l2-primos.begin();
        g=l1-primos.begin();
        //if(primos[h]==b) h++;
        cout<<(primos[g]>a?primos[g-1]:primos[g])<<' '<<primos[h]<<'\n';
    }
    return 0;
}

//transform (foo, foo+4, bar, result, std::logical_and<bool>());
