//
//  main.cpp
//  situation
//
//  Created by Franco Ariel Ramirez Villa on 05/08/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
unsigned long long x[100000];
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int c,i,j;
    cin>>c;
    for (i=j=0; i<c; i++) {
        cin>>x[i];
    }
    sort(x, x+c);
    //for (i=0; i<c; i++) {
    //  cout<<x[i]<<endl;
    //}
    for (i=0; i<c-2; i++) {
        for (j=i+1; j<c-1; j++) {
            if ((x[i]+x[j]>x[j+1])) {
                cout<<"possible\n";
                return 0;
            }
        }
    }
    cout<<"impossible\n";
    return 0;
}
