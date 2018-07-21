//
//  main.cpp
//  1362
//
//  Created by Franco Ariel Ramirez Villa on 14/06/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
long long euclides(long long a,long long b){
    if (!b) return a;
    return euclides(b, a%b);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long a,b,c;
    while (cin>>a>>b>>c, !(!a && !b && !c)) {
        if (!a && !b) cout<<"NO\n";
        else if(!(c%euclides(a, b))) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
