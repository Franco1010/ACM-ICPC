//
//  main.cpp
//  park
//
//  Created by Franco Ariel Ramirez Villa on 10/06/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(4);
    const double raiz=sqrt(3);
    int t,cont;
    char x;
    short int n;
    long double s,l1,l2,y;
    cin>>t;
    while (t--) {
        cin>>n;
        s=cont=l1=l2=0;
        while (n--) {
            cin>>x>>y;
            if (cont<=1) {
                l1+=y;
            }
            switch (x) {
                case 'C':
                    cont++;
                    s+=y*y;
                    break;
                case 'T':
                    s+=(y*y*raiz)/4;
                    break;
                case 'S':
                    s+=y*y;
                    break;
            }
            if (cont>=2 && cont<=3) {
                l2+=y;
                if (cont==3)cont++;
            }
        }
        //cout<<l1<<' '<<l2<<' '<<s<<endl;
        l1*=l2;
        l1-=s;
        cout<<l1<<'\n';
    }
    return 0;
}
