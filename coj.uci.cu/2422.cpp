#include <iostream>
#include <vector>
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
using namespace std;
long long int modular_pow(long long int base, long long int exponent,long long int modulus){
    long long int result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % modulus;
        
        exponent = exponent >> 1;
        
        base = (base * base) % modulus;
    }
    return result;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long int c,a,b;
    cin>>c;
    while (c--) {
        cin>>a>>b;
        cout<<modular_pow(a, b, 1000000000)<<'\n';
    }
    return 0;
}
