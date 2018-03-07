//
//  main.c
//  1064
//
//  Created by Franco Ariel Ramirez Villa on 06/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,c,d,x,y,min;
    while (1) {
        scanf("%i%i%i%i",&a,&b,&c,&d);
        if (a==0 && b==0 && c==0 && d==0) break;
        x=(a*60)+b;
        y=(c*60)+d;
        min=1440-(x-y);
        min=min%1440;
        printf("%i\n",min);
    }
    return 0;
}
