//
//  main.c
//  1023
//
//  Created by Franco Ariel Ramirez Villa on 09/12/16.
//  Copyright © 2016 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main() {
    float datos[12];
    for (int i=0; i<12; i++) {
        scanf("%f",&datos[i]);
    }
    float suma=0;
    for(int i=0;i<12;i++){
        suma+=datos[i];
    }
    
    printf("$%.2f\n",(suma/12));
    return 0;
}
