

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAX 50000
vector <int> primos;
void SieveOfAtkin(long long int limit) {
    long long int n,y,x,r,i; int a;
    bool sieve[limit];
    for (i=0; i<limit; i++)
        sieve[i] = false;
    sieve[2]=true; sieve[3]=true;
    for ( x = 1; x*x < limit; x++) {
        for ( y = 1; y*y < limit; y++) {
            n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;
            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true; }
    }
    for (r = 5; r*r < limit; r++) {
        if (sieve[r]) {
            for (i= r*r; i < limit; i += r*r) sieve[i] = false;
        } }
    for (a = 2; a < limit; a++) if (sieve[a])
        primos.push_back(a); }

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    SieveOfAtkin(MAX);
    int n,i,cont,r;
    long p=primos.size();
    long long num,primo = 0,modulo;
    double ar,ab;
    cin>>n;
    while (n--) {
        cin>>r;
        ar=r;
        ab=1;
        num=r;
        cont=0;
        for(i=0;i<p && num>1;i++){
            primo=primos[i];
            modulo=num%primo;
            while(modulo==0 && num>1){
                cont++;
                num/=primo;
                modulo=num%primo;
            }
            if(cont!=0){
                ar*=primo-1;
                ab*=primo;
            }
            cont=0;
        }
        if(num>1){
        ar*=num-1;
        ab*=num;
        }
        ar/=ab;
        cout<<fixed;
        cout<<setprecision(0)<<ar<<" "<<setprecision(4)<<ar/2<<'\n';
    }
    return 0;
    
}







