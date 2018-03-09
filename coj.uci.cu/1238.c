//
//  main.c
//  1238
//
//  Created by Franco Ariel Ramirez Villa on 06/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

long int factorial (int x){
    int i;
    long int fac = 1;
    for (i=2; i<=x; i=i+1) fac=fac*i; return (fac);
}

int main() {
    int r;
    char num[5];
    while (1) {
        scanf("%s",num); if (num[0]=='0') break;
        r=0;
        for (int i=0; i<strlen(num); i++) {
            r+=(num[i]-48)*factorial((strlen(num)-i));
        }
        printf("%i\n",r);
    }
    return 0;
}
