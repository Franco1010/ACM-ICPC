//
//  main.cpp
//  zigzag
//
//  Created by Franco Ariel Ramirez Villa on 26/05/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int t;
    long l;
    cin>>t;
    vector<string>cad(200);
    cad[0]="a";
    for (int i=1; i<=t+1; i++) {
        for (int j='a'; j<='z'; j++) {
            if (i-(j-96)>=0) {
                l=i-(j-96);
                if (((l)+abs(cad[l].back()-j))==i-1) {
                    cad[i]=cad[l];
                    cad[i]+=(char)j;
                }
            }
        }
    }
    //cout<<cad[t]<<endl;
    for (int i=0; i<100; i++) {
    cout<<i<<' '<<cad[i]<<endl;
    }
    cout<<"-----------"<<cad[t+1]<<"-----------"<<endl;
    return 0;
}
