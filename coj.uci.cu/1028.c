//
//  main.c
//  1028
//
//  Created by Franco Ariel Ramirez Villa on 09/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    char a[1000],b[1000];
    int x,t,i,j;
    while (scanf("%s %s",a,b) !=EOF){
        x=0;t=0;i=0;
        while (i<strlen(a)) {
            j=x;
            while (j<strlen(b)) {
                if (a[i]==b[j]) {
                    t++;
                    x=j+1;
                    break;
                }
                j++;
            }
            i++;
        }
        if (t==strlen(a)) {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
