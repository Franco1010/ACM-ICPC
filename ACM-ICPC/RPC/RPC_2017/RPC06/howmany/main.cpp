//
//  main.cpp
//  howmany
//
//  Created by Franco Ariel Ramirez Villa on 10/06/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int c,i,j;
    long cont;
    while (cin>>c,c!=0) {
        unsigned int A[c];
        cont=0;
        for (i=0; i<c; i++) {
            cin>>A[i];
        }
        for (i=0; i<c; i++) {
            for (j=i+1; j<c; j++) {
                if (A[i]>A[j]) {
                    cont++;
                }
            }
        }
        cout<<cont<<'\n';
    }
    return 0;
}
