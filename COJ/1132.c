//
//  main.c
//  1132
//
//  Created by Franco Ariel Ramirez Villa on 11/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(){
    int c , num , k , suma;
    scanf("%d",&c);
    
    while( c-- ){
        
        scanf("%d",&num);
        suma=0;
        
        for( k=1 ; k*k<num ; k++ )
            if( num%k == 0 )
                suma += k + num/k;
        
        if( k*k == num )
            suma+=k;
        
        printf("%d\n",suma-num);
    }
    
    return 0;
}

