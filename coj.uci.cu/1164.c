//
//  main.c
//  1164
//
//  Created by Franco Ariel Ramirez Villa on 26/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    long l=0,l2=0,da,db,z,na,nb;
    char a[100000],b[100000];
    while (scanf("%s %s",a,b),a[0]!='*') {
        da=db=z=0;
        while (a[da]=='0' && da<(strlen(a)-1)) {
            da++;
        }
        while (b[db]=='0' && db<(strlen(b)-1)) {
            db++;
        }
        l=strlen(a)-da;
        l2=strlen(b)-db;
        if (l<l2) printf("<\n");
        if (l>l2) printf(">\n");
        if (l==l2) {
            for (long i=0; i<l; i++) {
                na=a[da];nb=b[db];
                if (na<nb) {
                    printf("<\n");
                    z=1;
                    break;
                }
                if (na>nb) {
                    printf(">\n");
                    z=1;
                    break;
                }
                da++;db++;
            }
            if (z==0) printf("=\n");
        }
        
    }
    return 0;
}


