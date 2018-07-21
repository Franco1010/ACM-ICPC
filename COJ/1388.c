//
//  main.c
//  1388
//
//  Created by Franco Ariel Ramirez Villa on 07/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int c,a,num4,num2;
    char b[11];
    scanf("%i",&c);
    for (int i=0; i<c; i++) {
        scanf("%i%s",&a,b);
        num4=b[(strlen(b)-1)]-48;
        if (strlen(b)>1) {
            num4+=(b[(strlen(b)-2)]-48)*10;
        }
        num2=b[(strlen(b)-1)]-48;
        //printf("%i %i\n",num2,num4);
        if (atoi(b)==0)printf("1\n");
        else{
        if (a==0 || a==10 || a==20)printf("0\n");
        if (a==1 || a==11)printf("1\n");
        if (a==2 || a==12){
            if (num4%4==0)printf("6\n");
            if (num4%4==3)printf("8\n");
            if (num4%4==2)printf("4\n");
            if (num4%4==1)printf("2\n");
        }
        if (a==3 || a==13){
            if (num4%4==0)printf("1\n");
            if (num4%4==3)printf("7\n");
            if (num4%4==2)printf("9\n");
            if (num4%4==1)printf("3\n");
        }
        if (a==4 || a==14){
            if (num2%2==0)printf("6\n");
            if (num2%2==1)printf("4\n");
        }
        if (a==5 || a==15)printf("5\n");
        if (a==6 || a==16)printf("6\n");
        if (a==7 || a==17){
            if (num4%4==0)printf("1\n");
            if (num4%4==3)printf("3\n");
            if (num4%4==2)printf("9\n");
            if (num4%4==1)printf("7\n");
        }
        if (a==8 || a==18){
            if (num4%4==0)printf("6\n");
            if (num4%4==3)printf("2\n");
            if (num4%4==2)printf("4\n");
            if (num4%4==1)printf("8\n");
        }
        if (a==9 || a==19){
            if (num2%2==0)printf("1\n");
            if (num2%2==1)printf("9\n");
        }
        }
    }
    return 0;
}
