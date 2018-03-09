//
//  main.cpp
//  1252
//
//  Created by Franco Ariel Ramirez Villa on 05/02/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    long tam;
    string b="";
        while (true) {
            b="";
            getline(cin,a);
            tam=a.size();
            if(a[0]=='#' && tam==1) break;
            for (int i=0; i<tam; i++) {
                switch (a[i]) {
                    case ' ':
                        b+="%20";
                        break;
                    case '!':
                        b+="%21";
                        break;
                    case '$':
                        b+="%24";
                        break;
                    case '%':
                        b+="%25";
                        break;
                    case '(':
                        b+="%28";
                        break;
                    case ')':
                        b+="%29";
                        break;
                    case '*':
                        b+="%2a";
                        break;
                        
                    default: b+=a[i];
                        break;
                }
            }
            cout<<b<<endl;
        }
    return 0;
}
