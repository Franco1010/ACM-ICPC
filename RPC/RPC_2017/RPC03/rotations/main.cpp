//
//  main.cpp
//  rotations
//
//  Created by Franco Ariel Ramirez Villa on 28/04/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main (){
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    int c,i,cont;
    vector<bool>bin;
    long long num,num2 = 0;
    cin>>c;
    while (c--) {
        vector<bool>x(32,0);
        cin>>num;
        bin.clear();
        while (num) {
            bin.push_back(num%2);
            num/=2;
        }
        while (bin.size()<32) {
            bin.push_back(0);
        }
        bin.push_back(bin[0]);
        bin.push_back(bin[1]);
        bin.push_back(bin[2]);
        bin.push_back(bin[3]);
        for (i=0; i<32; i++) {
            num2=0;
            num2+=bin[i];
            num2+=bin[i+1]*2;
            num2+=bin[i+2]*4;
            num2+=bin[i+3]*8;
            num2+=bin[i+4]*16;
            x[num2]=true;
        }
        cont=0;
        for (i=0; i<32; i++) {
            if (x[i]) {
                cont++;
            }
        }
        //cout<<cont<<endl;
        cout<<(cont==32?"yes\n":"no\n");
    }
    return 0;
}
