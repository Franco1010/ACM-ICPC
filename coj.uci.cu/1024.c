//
//  main.c
//  1024
//
//  Created by Franco Ariel Ramirez Villa on 05/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    float x,a;
    int n;

    while (1) {
        scanf("%f",&x); if (x==0.00) break;
        n=0;a=0;
        for (int i=1; a<x; i++) {
            a+=powf((i+1),-1);
            n=i;
            }
        printf("%i card(s)\n",n);
    }
    return 0;
}
