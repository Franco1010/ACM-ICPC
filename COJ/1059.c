//
//  main.c
//  1059
//
//  Created by Franco Ariel Ramirez Villa on 29/12/16.
//  Copyright © 2016 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>


char cad[64],cad2[64];
int main() {
    long int num,sum;
    while (1) {
        memset(cad, 0, strlen(cad)); sum=0;
        scanf("%li",&num);
        if (num==0) break;
        char r[1];
        while (num!=0) {
            r[0]=num%2+48;
            num/=2;
            strcat(cad, r);
        }

        for (int j=0; j<strlen(cad); j++) {
            cad2[j]=cad[strlen(cad)-j-1];
        }
        
        for (int i=0; i<strlen(cad2); i++) {
            if (cad2[i]==49) sum++;
        }
        printf("The parity of %s is %li (mod 2).\n",cad2,sum);
    }
    return 0;
}


