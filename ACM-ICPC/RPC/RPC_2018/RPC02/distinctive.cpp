//
//  main.cpp
//  RPC02
//
//  Created by Crystal Rodriguez on 10/03/18.
//  Copyright © 2018 Crystal Rodriguez. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,i,j,cero,uno;
    
    cin>>a>>b;
    string x[a],aux;
    for(int i=0;i<a;i++){
        cin>>aux;
        x[i]=aux;
    }
    string final="";
    for(i=0;i<b;i++){
        cero=0;uno=0;
        for(j=0;j<a;j++){
            if(x[j][i]=='0' ) cero++;
            else uno++;
       }
        //cout<<cero<<" "<<uno<<'\n';
        if(cero>=uno ) final+='1';
        else final+='0';
        
    }
    cout<<final<<'\n';
    
}
