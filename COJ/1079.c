//
//  main.c
//  1079
//
//  Created by Franco Ariel Ramirez Villa on 11/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i=0,j,k,c,n,sum,sum2,x;
    scanf("%i",&c);
    while (i<c) {
        scanf("%i",&n);
        j=0;sum=0;
        while (j<n) {
            k=0;sum2=0;
            while (k<n) {
                scanf("%i",&x);
                sum2+=x;
                k++;
            }
            if (sum2>sum) {
                sum=sum2;
            }
            j++;
        }
        printf("%i\n",sum);
        i++;
    }
    return 0;
}
