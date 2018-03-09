//
//  main.c
//  1118
//
//  Created by Franco Ariel Ramirez Villa on 23/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int c,num,m,r;
    scanf("%i",&c);
    while (c--) {
        scanf("%i",&num);
        r=0;
        char celdas[num];
        memset(celdas, 'O', num);
        m=2;
        while (m<=num) {
            for (int i=(m-1); i<num; i+=m) {
                if (celdas[i]=='O') celdas[i]='C';
                else {
                    if (celdas[i]=='C') celdas[i]='O';
                }
            }
            m++;
        }
        for (int i=0; i<num; i++) {
            if (celdas[i]=='O') r++;;
        }
        printf("%i\n",r);
    }
    return 0;
}
