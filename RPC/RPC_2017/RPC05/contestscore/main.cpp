

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k,i;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long int suma=0,suma1 = 0;
    cin>>n>>k;
    vector<int>tiempo(n);
    for(i=0;i<n;i++){
        cin>>tiempo[i];
    }
    long siz=tiempo.size();
    while(siz>0){
        if(siz>=k) sort(tiempo.begin(),tiempo.begin()+k);
        else if(siz<k) sort(tiempo.begin(),tiempo.end());
        suma+=tiempo[0];
        suma1+=suma;
        tiempo.erase(tiempo.begin());
        siz=tiempo.size();
    }
    cout<<suma1<<'\n';
}
