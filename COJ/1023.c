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


/*100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75*/
