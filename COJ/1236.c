//
//  main.c
//  1236
//
//  Created by Franco Ariel Ramirez Villa on 31/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(){
    int a,b,c,d,p,m,g,x=0,y=0,z=0;
    scanf("%i%i%i%i%i%i%i",&a,&b,&c,&d,&p,&m,&g);
    if ((p%(a+b))<=a && (p%(a+b))>0) x++;
    if ((p%(c+d))<=c && (p%(c+d))>0) x++;
    if ((m%(a+b))<=a && (m%(a+b))>0) y++;
    if ((m%(c+d))<=c && (m%(c+d))>0) y++;
    if ((g%(a+b))<=a && (g%(a+b))>0) z++;
    if ((g%(c+d))<=c && (g%(c+d))>0) z++;
    if (x==0)printf("none\n");
    if (x==1)printf("one\n");
    if (x==2)printf("both\n");
    if (y==0)printf("none\n");
    if (y==1)printf("one\n");
    if (y==2)printf("both\n");
    if (z==0)printf("none\n");
    if (z==1)printf("one\n");
    if (z==2)printf("both\n");
    return 0;
}
