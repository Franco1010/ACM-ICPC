//
//  main.c
//  1016
//
//  Created by Franco Ariel Ramirez Villa on 22/01/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int c,bo = 0,t=1;
    scanf("%i",&c);
    float point[c][2],S[c][2],pd = 0.0,d = 0.0,r=0.0;
    for (int i=0; i<c; i++) {
        for (int j=0; j<2; j++) {
            scanf("%f",&point[i][j]);
        }
    }
    S[0][0]=point[0][0];
    S[0][1]=point[0][1];
    point[0][0]=123454321;
    point[0][1]=12345;
    
    while (t<c) {
        d=999999999999999999;
        for (int i=0; i<t; i++) {
            for (int j=0; j<c; j++) {
                if (point[j][0]!=123454321){
                    pd=sqrtf(powf((S[i][0]-point[j][0]), 2) + powf((S[i][1]-point[j][1]), 2));
                    if (pd<d && pd!=0){
                        d=pd;
                        bo=j;
                    }
                }
            }

        }
        S[t][0]=point[bo][0];
        S[t][1]=point[bo][1];
        point[bo][0]=123454321;
        point[bo][1]=123454321;
        r+=d;
        t++;
        
    }
    printf("%.2f\n",r);
    return 0;
}
