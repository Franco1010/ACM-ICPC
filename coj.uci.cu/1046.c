//
//  main.c
//  1046
//
//  Created by Franco Ariel Ramirez Villa on 09/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,casos,suma;
    scanf("%i",&casos);
    for (int i=0; i<casos; i++) {
        scanf("%i%i",&a,&b);
        suma=0;
        for (int j=a; j<=b; j++) {
            suma+=j*(j+1)*(j+2);
            suma%=100;
        }
        printf("%i\n",suma);
    }
    return 0;
}
