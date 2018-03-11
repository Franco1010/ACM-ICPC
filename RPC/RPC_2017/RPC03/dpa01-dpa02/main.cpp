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
        primos.push_back(a); }

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    SieveOfAtkin(1000000);
    int n,i,aux,cont,r;
    long long num,sum,prod,primo = 0,modulo;
    cin>>n;
    while (n--) {
        //vector <long long int> p;
        cin>>r;
        sum=0;
        prod=1;
        i=0;
        num=r;
        cont=0;
        while(num>1){
            primo=primos[i];
            modulo=num%primo;
            if(modulo==0){
                cont++;
                num/=primo;
            }
            if(modulo!=0){
                if(cont>0){
                    sum=0;
                    for(aux=0;aux<=cont;aux++){
                        sum+=pow(primo,aux);
                    }
                    prod*=sum;
                    cont=0;
                }
                i++;
            }
            if(i==primos.size()){
                primos.push_back(num);
                cont++;
                num/=num;
            }
        }
        if(cont>0){
            sum=0;
            for(aux=0;aux<=cont;aux++){
                sum+=pow(primo,aux);
            }
            prod*=sum;
        }
        prod-=r;
        if(prod==r)cout<<"perfect\n";
        else if (prod<r)cout<<"deficient\n";
        else cout<<"abundant\n";
    }
    return 0;
    
}







