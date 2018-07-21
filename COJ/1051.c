//
//  main.c
//  1051
//
//  Created by Franco Ariel Ramirez Villa on 19/12/16.
//  Copyright © 2016 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    int R=0,sum=0,num=0;
    scanf("%i",&num);
    
    sum=num/3;
    if (num%3!=0)sum++;
    R=num-sum;
    printf("%i\n",R);
    return 0;
}
