#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD 1000000007
long long int x[100];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long int c,i,num,pos;
    unsigned long long int min=-1;
    cin>>c;
    for (i=0; i<c; i++) {
        cin>>x[i];
    }
    cin>>num;
    for (i=0; i<c; i++) {
        if (num%x[i]<min) {
            min=num%x[i];
            pos=i;
        }
    }
    cout<<x[pos]<<'\n';
    return 0;
}


