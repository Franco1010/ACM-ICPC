//
//  main.cpp
//  hulam
//
//  Created by Franco Ariel Ramirez Villa on 02/09/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x,a;
    cin>>x;
    while(x--){
        cin>>a;
        switch(a){
            case 1:
                cout<<1<<'\n';
                break;
            case 2:
                cout<<2<<'\n';
                break;
            default:
                a-=2;
                a*=3;
                a++;
                cout<<a<<'\n';
                break;
        }
    }
}
