//
//  main.cpp
//  foosball
//
//  Created by Franco Ariel Ramirez Villa on 09/07/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
//wo,bo,wd,bd
using namespace std;
int main(){
    int i,l,cont=0,max=0;
    vector<int>scores;
    vector<string>dynasties[2];
    string jugadores[4];
    queue<string>cola;
    string gana[2];
    int c;
    string aux,cam;
    cin>>c;
    cin>>jugadores[0];
    cin>>jugadores[1];
    cin>>jugadores[2];
    cin>>jugadores[3];
    for (i=0; i<c-4; i++) {
        cin>>aux;
        cola.push(aux);
    }
    cin>>aux;
    l=aux.size();
    for (i=cont=0; i<l; i++) {
        if(cont==0){if(aux[i]=='W'){gana[0]=jugadores[0];gana[1]=jugadores[2];} else{gana[0]=jugadores[1];gana[1]=jugadores[3];}}
        if (aux[i]=='W') {
            cam=jugadores[0];
            jugadores[0]=jugadores[2];
            jugadores[2]=cam;
            
            cam=jugadores[3];
            jugadores[3]=jugadores[1];
            jugadores[1]=cola.front();
            cola.pop();
            cola.push(cam);
        }else{
            cam=jugadores[1];
            jugadores[1]=jugadores[3];
            jugadores[3]=cam;
            
            cam=jugadores[2];
            jugadores[2]=jugadores[0];
            jugadores[0]=cola.front();
            cola.pop();
            cola.push(cam);
        }
        cont++;
        if (i>0 && aux[i]!=aux[i-1]) {
            scores.push_back(cont);
            dynasties[0].push_back(gana[0]);
            dynasties[1].push_back(gana[1]);
            if (cont>max) {
                max=cont;
            }
            cont=0;
        }
        
    }
    if(cont>0){
        scores.push_back(cont);
        dynasties[0].push_back(gana[0]);
        dynasties[1].push_back(gana[1]);
        if (cont>max) {
            max=cont;
        }
    }
    l=scores.size();
    for (i=0; i<l; i++) {
        cout<<dynasties[0][i]<<' '<<dynasties[1][i]<<' '<<scores[i]<<endl;
        //if (scores[i]==max) {
          //  cout<<dynasties[0][i]<<' '<<dynasties[1][i]<<endl;
        //}
    }
    return 0;
}
