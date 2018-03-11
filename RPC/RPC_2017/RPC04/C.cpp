
//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cmath>
#include <iomanip>
#define ENDL '\n'
using namespace std;
long long original[1000000][2];//0->distancias 1->alturas
long long orden[1000000][2];//0->derecha 1->izquierda
double dis[1000000][2];//0->derecha 1->izquierda
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    long long int c,i,p;
    stack<unsigned long long>m[2];// 0->alturas 1->poscion en el orden que llegaron
    m[0].push(-1);
    cin>>c;
    c+=2;
    for(i=0; i<c; i++){
        cin>>original[i][0]>>original[i][1];
    }
    
    for (i=0; i<c; i++) {
        if (original[i][1]>m[0].top()) {
            while (original[i][1]>m[0].top()) {
                orden[m[1].top()][1]=i;
                m[1].pop();
                m[0].pop();
            }
            m[0].push(original[i][1]);
            m[1].push(i);
        }
        else{
            m[0].push(original[i][1]);
            m[1].push(i);
        }
    }
    while (!m[0].empty()) {
        m[0].pop();
    }
    while (!m[1].empty()) {
        m[1].pop();
    }
    m[0].push(-1);
    
    //-------------------------------------//
    for (i=c; i>=0; i--) {
        if (original[i][1]>m[0].top()) {
            while (original[i][1]>m[0].top()) {
                orden[m[1].top()][0]=i;
                m[1].pop();
                m[0].pop();
            }
            m[0].push(original[i][1]);
            m[1].push(i);
        }
        else{
            m[0].push(original[i][1]);
            m[1].push(i);
        }
    }
    for (i=1; i<c-1; i++) {
        p=orden[i][0];
        dis[i][0]=pow(abs(original[i][1]-original[p][1]), 2);
        dis[i][0]+=pow(original[i][0]-original[p][0], 2);
        dis[i][0]=sqrt(dis[i][0]);
        p=orden[i][1];
        dis[i][1]=pow(abs(original[i][1]-original[p][1]), 2);
        dis[i][1]+=pow(original[i][0]-original[p][0], 2);
        dis[i][1]=sqrt(dis[i][1]);
    }
    cout<<fixed<<setprecision(4);
    for (i=1; i<c-1; i++) {
        cout<<orden[i][0]<<' '<<orden[i][1]<<' '<<' '<<dis[i][0]<<' '<<dis[i][1]<<ENDL;
    }
    return 0;
}
