//
//  main.c
//  1004
//
//  Created by Franco Ariel Ramirez Villa on 04/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int c,a,b;
    scanf("%i",&c);
    for (int i=0; i<c; i++) {
        scanf("%i%i",&a,&b);
        if (a%2==0 && b%2==0 && a>b) {
            printf("U\n");
        }
        if (a%2==0 && b%2==0 && a<=b) {
            printf("L\n");
        }
        if (a%2==0 && b%2!=0 && a>b) {
            printf("D\n");
        }
        if (a%2==0 && b%2!=0 && a<b) {
            printf("L\n");
        }
        if (a%2!=0 && b%2==0 && a>b) {
            printf("U\n");
        }
        if (a%2!=0 && b%2==0 && a<b) {
            printf("R\n");
        }
        if (a%2!=0 && b%2!=0 && a>b) {
            printf("D\n");
        }
        if (a%2!=0 && b%2!=0 && a<=b) {
            printf("R\n");
        }
    }
    return 0;
}
