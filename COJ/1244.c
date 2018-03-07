//
//  main.c
//  1244
//
//  Created by Franco Ariel Ramirez Villa on 31/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    char cad[1000]="\0",Ini;
    int espacio,letra;
    while (1) {
        scanf(" %[^\n]",cad); if (cad[0]=='*')break;
        Ini=cad[0];espacio=0;letra=0;
        for (int i=0; i<strlen(cad)-1; i++) {
            if (cad[i]==' ') {
                espacio++;
                if ((cad[i+1]==Ini) || (cad[i+1]==Ini+32) || (cad[i+1]==Ini-32)) {
                    letra++;
                }
            }
        }
        if (espacio==letra) printf("Y\n");
        if (espacio!=letra) printf("N\n");
    }
    return 0;
}
