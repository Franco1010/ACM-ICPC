//
//  main.cpp
//  problem.cpp
//
//  Created by Franco Ariel Ramirez Villa on 10/06/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    short int c;
    string cad;
    cin>>c;
    while (c--) {
        cin>>cad;
        if (cad.size()==1 && (cad[0]=='1' || cad[0]=='0')) {
            if (cad[0]=='1') {
                cout<<66<<'\n';
            }else cout<<1<<'\n';
        }else{
            switch (cad.back()) {
                case '0':
                case '5':
                    cout<<76<<'\n';
                    break;
                case '1':
                case '6':
                    cout<<16<<'\n';
                    break;
                case '2':
                case '7':
                    cout<<56<<'\n';
                    break;
                case '3':
                case '8':
                    cout<<96<<'\n';
                    break;
                case '4':
                case '9':
                    cout<<36<<'\n';
                    break;
            }
        }
    }
    return 0;
}
