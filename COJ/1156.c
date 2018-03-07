//
//  main.c
//  1156
//
//  Created by Franco Ariel Ramirez Villa on 04/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    int a;
    while (1) {
        scanf("%i",&a);
        if (a==42) {
            break;
        }
        else printf("%i\n",a);
    }
    return 0;
}
