//
//  main.cpp
//  RPC02
//
//  Created by Crystal Rodriguez on 10/03/18.
//  Copyright © 2018 Crystal Rodriguez. All rights reserved.
//


#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct equipo
{
    int num, pro=NULL, ti=NULL;
    bool operator<(const equipo &t) const
    {
        return pro > t.pro || (pro==t.pro && ti<t.ti) ;
    }
    
};

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b,i,j,eq,tiempo, actual;
    cin>>a>>b;
    equipo equipos[a];
    //int indices[a];
    for(i=0;i<a;i++){ equipos[i].num=i+1;}
    actual=0;
    for(i=0;i<b;i++){
        cin>>eq>>tiempo;
        for (j=0; j<a; j++) {
            if (equipos[j].num==eq) {
                equipos[j].pro+=1;
                equipos[j].ti=tiempo;
                break;
            }
        }
        while (j>0 && equipos[j]<equipos[j-1]) {
            swap(equipos[j], equipos[j-1]);
            j--;
        }
        for (j=0; j<a; j++) {
            if(equipos[j].num==1){
                cout<<j+1<<'\n';
                break;
            }
        }
    }
    
    return 0;
    
}
