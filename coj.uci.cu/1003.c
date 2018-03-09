//
//  main.c
//  1003
//
//  Created by Franco Ariel Ramirez Villa on 09/12/16.
//  Copyright © 2016 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>

int main(){
    int x; scanf("%i",&x);
    for (int i=0; i<x; i++) {
        int columnas,filas;
        scanf("%i %i",&columnas,&filas);
        int matriz[filas][columnas];
        for (int j=0; j<filas; j++) {
            for (int k=0; k<columnas; k++){
                scanf("%i",&matriz[j][k]);

            }
        }
        for(int l=0;l<filas;l++){
            printf("%i%",matriz[l]);

    }
    return 0;
}
