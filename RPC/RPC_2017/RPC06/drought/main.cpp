//
//  main.cpp
//  drought
//
//  Created by Franco Ariel Ramirez Villa on 10/06/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int c,a,n,i,al,al2;
    long long int volumen;
    cin>>c;
    while (c--) {
        cin>>a>>n;
        volumen=0;
        int ancho[n];
        for (i=0; i<n; i++) {
            cin>>ancho[i];
        }
        int j=0,aux=0;
        for (i=0; i<=n; i++) {
            cin>>al;
            if(i>0){
                if(al>aux) al2=aux*ancho[j++];
                else al2=ancho[j++]*al;
                volumen+=al2;
            }
            aux=al;
        }
        volumen*=a;
        cout<<volumen<<'\n';
    }
    return 0;
}
