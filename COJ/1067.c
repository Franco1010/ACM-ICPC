//
//  main.c
//  1067
//
//  Created by Franco Ariel Ramirez Villa on 09/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    int a,b,num=0,x=1;
    char cad[10];
    do {
        a=0;b=11;
        do {
            if(x>0){scanf("%i",&num);x++;}
            scanf("\n%[^\n]",cad);
            if (strcmp(cad, "too high")==0 && num<b) {
                b=num;
            }
            if (strcmp(cad, "too low")==0 && num>a) {
                a=num;
            }
        } while (strcmp(cad, "too high")==0 || strcmp(cad, "too low")==0);
        if (a<num && num<b) {
            printf("Stan may be honest\n");
        }
        if (a>num || b<num) {
            printf("Stan is dishonest\n");
        }
        scanf("%i",&num);
        x=0;
    } while (num!=0);
    return 0;
}
