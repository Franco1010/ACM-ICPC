//
//  main.cpp
//  cryptography
//
//  Created by Franco Ariel Ramirez Villa on 08/07/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    cin.tie();
    ios_base::sync_with_stdio(0);
    long l;
    string s,c;
    cin>>s>>c;
    l=s.size();
    for (int i=0; i<l; i++) {
        s[i]=((s[i]-65)-(c[i]-65)+26)%26;
        s[i]+=65;
        c+=s[i];
    }
    cout<<s<<'\n';
    return 0;
}
