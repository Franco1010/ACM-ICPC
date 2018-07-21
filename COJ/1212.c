//
//  main.c
//  1212
//
//  Created by Franco Ariel Ramirez Villa on 27/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//
//WHQESTX
#include <stdio.h>
#include <string.h>

int main() {
    int r;
    float rp;
    char notas[200];
    while (scanf(" %s",notas),notas[0]!='*') {
        rp=0.0;r=0;
        for (int i=0; i<strlen(notas); i++) {
            if (notas[i]=='W')rp+=1;
            if (notas[i]=='H')rp+=0.5;
            if (notas[i]=='Q')rp+=0.25;
            if (notas[i]=='E')rp+=0.125;
            if (notas[i]=='S')rp+=0.0625;
            if (notas[i]=='T')rp+=0.03125;
            if (notas[i]=='X')rp+=0.015625;
            if (notas[i]=='/') {
                if (rp==1.0) {
                    r++;
                }
                rp=0.0;
            }
        }
        printf("%i\n",r);
    }
    return 0;
}
