//
//  main.cpp
//  battle
//
//  Created by Franco Ariel Ramirez Villa on 05/08/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string x,y="";
    cin>>x;
    long long l=x.size(),tam=('R'+'B'+'L');
    for (long long i=0; i<l; i++) {
        if (i<l-2 && x[i]+x[i+1]+x[i+2]==tam) {
            y+='C';
            i+=2;
        }
        else if (x[i]=='R')y+='S';
        else if (x[i]=='B')y+='K';
        else y+='H';
    }
    cout<<y<<'\n';
    return 0;
}
