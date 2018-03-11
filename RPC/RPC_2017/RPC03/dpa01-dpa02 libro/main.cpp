//
//  main.cpp
//  dpa01-dpa02
//
//  Created by Franco Ariel Ramirez Villa on 28/04/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector <long long int> primos;
void SieveOfAtkin(long long int limit) {
    long long int n,y,x,r,i; int a;
    bool sieve[limit];
    for (int i=0; i<limit; i++)
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
        primos.push_back(a);
}

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primos[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1); PF = primos[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
    return ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    SieveOfAtkin(1000000);
    int n,r;
    long long sum,prod;
    cin>>n;
    while (n--) {
        //vector <long long int> p;
        cin>>r;
        sum=0;
        prod=sumDiv(r);
        cout<<prod<<endl;
        prod-=r;
        if(prod==r)cout<<"perfect\n";
        else if (prod<r)cout<<"deficient\n";
        else cout<<"abundant\n";
    }
    return 0;
    
}







