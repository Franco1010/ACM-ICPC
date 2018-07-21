#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b;
    cin>>a;
    while(a--){
        cin>>b;
        int lista[b+1];
        for(int i=0;i<b;i++){
            cin>>lista[i];
        }
        sort(lista,lista+b);
        int ne[b];
        int x=0;
        for(int i=b-1;i>=0;i--){
            ne[x]=lista[i];
            x++;
        }
        long long int suma=0;
        for(int i=0;i<b;i++){
            if(i%3==2){
                suma+=ne[i];
            }
        }
        cout<<suma<<endl;
    }
    return 0;
}
