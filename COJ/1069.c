//
//  main.c
//  1069
//
//  Created by Franco Ariel Ramirez Villa on 06/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int x,a,b,c,s,S;
    scanf("%i",&x);
    
    for (int i=0; i<x; i++) {
        scanf("%i%i%i",&a,&b,&c); if (c==0 || c==1) {printf("0\n");}
        else{
            s=0;S=0;
            a+=b;
            while (a/c) {
                s=a/c;
                a-=s*c;
                a+=s;
                S+=s;
            }
            printf("%i\n",S);
        }
    }
    return 0;
}
