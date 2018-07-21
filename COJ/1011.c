//
//  main.c
//  1011
//
//  Created by Franco Ariel Ramirez Villa on 11/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c=0,i=0,j,k,ng,nm,sng,snm,x;
    scanf("%i",&c);
    while (i<c) {
        scanf(" \n");
        scanf(" %i %i",&ng,&nm);
        j=0;k=0;sng=0;snm=0;
        while (j<ng) {
            scanf(" %i",&x);
            sng+=x;
            j++;
        }
        while (k<nm) {
            scanf(" %i",&x);
            snm+=x;
            k++;
        }
        if (sng==snm && sng!=1) {
            printf("uncertain\n");
        }else{
            if (sng==1 && snm==1) {
                printf("Godzilla\n");
            }else{
                if (sng>snm) {
                    printf("Godzilla\n");
                }else printf("MechaGodzilla\n");
            }
        }
        
        i++;
    }
    return 0;
}
