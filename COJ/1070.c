//
//  main.c
//  1070
//
//  Created by Franco Ariel Ramirez Villa on 06/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>


int main() {
    int n,c,r;
    while (scanf("%i",&n) !=EOF){
        c=(n*(n+1)*(2*n+1)/6);
        r=(n*(n+1)/2)*(n*(n+1)/2);
        printf("%i %i\n",c,r);
    }
    return 0;
}
