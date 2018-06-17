//
//  main.cpp
//  equality
//
//  Created by Franco Ariel Ramirez Villa on 13/05/17.
//  Copyright © 2017 Franco Ariel Ramirez Villa. All rights reserved.
//

#include <cstdio>
//#include <bits/stdc++.h>
int main(){
    int a,b;
    scanf("%i + %i = ",&a,&b);
    a+=b;
    scanf("%i",&b);
    printf("%s",(a==b?"YES\n":"NO\n"));
    return 0;
}
