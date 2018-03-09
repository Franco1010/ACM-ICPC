//
//  main.c
//  1043
//
//  Created by Franco Ariel Ramirez Villa on 10/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int r,medida,lista[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
    long long int a,x,sum;
    scanf("%i",&r);
    for(int i=0;i<r;i++){
        scanf("%llu",&a);
        int res[16];
        sum=0;medida=0;
        x=a;
        while (sum<a) {
            for (int j=0; j<16; j++) {
                if (lista[j]>x) {
                    res[medida]=(j-1);
                    //printf("%i\n",j-1);
                    sum+=lista[j-1];
                    x-=lista[j-1];
                    medida++;
                    break;
                   
                }
            }
        }
        for (int k=medida-1; k>=0; k--) {
            printf("%i ",res[k]);
        }printf("\n");
    }
    return 0;
}
