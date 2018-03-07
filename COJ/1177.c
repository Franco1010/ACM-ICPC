//
//  main.c
//  1177
//
//  Created by Franco Ariel Ramirez Villa on 10/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    int ciclos=4,chingado=0;
    long int tamloop,n;
    char cad[105],fcad[105],h;
    strcpy(cad, "casa");
    while (1) {
        if (chingado>0) {
            scanf("%i",&ciclos);if(ciclos==0)break;
            scanf("%s",cad);
        }
        tamloop=strlen(cad)/ciclos;
        char cadx[tamloop],ncad[tamloop];
        memset(fcad,'\0', 105);
        memset(ncad,'x', tamloop);
        memset(cadx,'x', tamloop);
        for (long i=0; i<ciclos; i++) {
            n=i*tamloop;
            for (long j=n; j<(n+tamloop); j++) {
                h=cad[j];
                cadx[(j-n)]=h;
            }
            for (long k=0; k<tamloop; k++) {
                ncad[k]=cadx[tamloop-k-1];
            }
            strcat(fcad, ncad);
        }
        if (chingado>0) {
            printf("%s\n",fcad);
        }
        chingado++;
    }
    return 0;
}
