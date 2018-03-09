//
//  main.c
//  1160
//
//  Created by Franco Ariel Ramirez Villa on 03/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int c,x,y;
    scanf("%i",&c);
    for (int i=0; i<c; i++) {
        scanf("%i%i",&x,&y);
        if (x!=y && x!=(y+2)) {
            printf("No Number\n");
        }
        else{
            if (y%2==0) {
                if (x==y) {
                    printf("%i\n",(x*2));
                }
                else printf("%i\n",(y*2+2));
                }
            else{
                if (x==y) {
                    printf("%i\n",(x*2-1));
                }
                else printf("%i\n",(y*2+1));
            }
        }
    }
    return 0;
}
