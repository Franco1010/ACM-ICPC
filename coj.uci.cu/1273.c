//
//  main.c
//  1273
//
//  Created by Franco Ariel Ramirez Villa on 24/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(){
    int c,v1,v2,v3;
    scanf("%i",&c);
    while (c--) {
        scanf("%i %i %i",&v1,&v2,&v3);
        v1=((v1+1)*(v1+2))/2;
        v1*=v2*v3;
        printf("%i\n",v1);
    }
    return 0;
}
