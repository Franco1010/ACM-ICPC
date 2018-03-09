//
//  main.c
//  1288
//
//  Created by Franco Ariel Ramirez Villa on 16/12/16.
//  Copyright © 2016 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char num[1000];
int y=0;
int main() {
    scanf("%i", &y);
    for (int i=0; i<y; i++) {
        int sum=0;
        scanf("%s", num);
        for (int i=0; i<(strlen(num)); i++) {
            sum+=num[i];
        }
        int div2=(num[strlen(num)-1]);
        if (sum%3==0 && div2%2==0){
            printf("YES\n");}
        else {
            printf("NO\n");}
    }
    return 0;
}
