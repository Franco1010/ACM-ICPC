//
//  main.c
//  1179
//
//  Created by Franco Ariel Ramirez Villa on 23/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c,num,t,tmax = 0,tmin = 0,p=0,r;
    scanf("%i",&c);
    while (c--) {
        r=0;
        scanf("%i",&num);
        p=0;
        while (num--) {
            scanf("%i",&t);
            if (p==0) {
                tmin=t;
                tmax=t;
            }
            if (t<tmin) tmin=t;
            if (t>tmax) tmax=t;
            p++;
        }
        r=(tmax-tmin)*2;
        printf("%i\n",r);
    }
    return 0;
}
