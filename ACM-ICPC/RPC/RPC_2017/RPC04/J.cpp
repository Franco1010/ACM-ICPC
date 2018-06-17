
#include <bits/stdc++.h>
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <bitset>
#define ENDL '\n'
using namespace std;
long long _sieve_size;
bitset<10000010> bs;
vector<int>primes;

void sieve(long long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    sieve(1000);
    unsigned int n,x,y,rango,i,cont,divs,j;
    while (true) {
        cont=0;
        cin>>n>>x>>y; if(x==y && y==n && n==0)break;
        rango=y-x;
        for(i=x;i<=rango;i++){
            divs=0;
            for (j=0; primes[j]<=i; j++) {
                if (i%primes[j]==0) divs++;
            }
            cont+=divs;
        }
        cont=cont*(pow(2, (y-x-1)));
        cout<<cont<<ENDL;
    }
    return 0;
}
