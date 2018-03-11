//
//  main.cpp
//  talkingp
//
//  Created by Franco Ariel Ramirez Villa on 02/09/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<string>s;
    string x;
    int c,i,j;
    long long l;
    cin>>c;
    cin.get();
    for (i=0; i<c; i++) {
        getline(cin, x);
        
        s.push_back(x);
    }
    for (i=0; i<c; i++) {
        l=s[i].size();
        for (j=0; j<l; j++) {
            switch (s[i][j]) {
                case 'a':
                    s[i].insert(j+1, "pa");
                    j+=2;
                    l+=2;
                    break;
                case 'e':
                    s[i].insert(j+1, "pe");
                    j+=2;
                    l+=2;
                    break;
                case 'i':
                    s[i].insert(j+1, "pi");
                    j+=2;
                    l+=2;
                    break;
                case 'o':
                    s[i].insert(j+1, "po");
                    j+=2;
                    l+=2;
                    break;
                case 'u':
                    s[i].insert(j+1, "pu");
                    j+=2;
                    l+=2;
                    break;
            }
        }
        cout<<s[i]<<'\n';
    }
    return 0;
}
