#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b,c,d,aux,i;
    cin>>a>>b>>c>>d;
    if(c==d) {
        for(i=0;i<2*b;i++)cin>>aux;
        cout<<"leave\n";
        return 0;
    }
    float fs[a];
    for(i=0;i<a;i++)fs[i]=0;
    int pares[b][2];
    for(i=0;i<b;i++){
        cin>>pares[i][0];
        fs[pares[i][0]-1]++;
        cin>>pares[i][1];
        fs[pares[i][1]-1]++;
    }
    int late[a];
    for(i=0;i<a;i++) late[i]=fs[i];
    while(1){
        fs[d-1]=0;
        for(i=0;i<b;i++){
            if(pares[i][0]==d){
                late[pares[i][1]-1]--;
                late[pares[i][0]-1]=0;
            }
            if(pares[i][1]==d){
                late[pares[i][0]-1]--;
                late[pares[i][1]-1]=0;
            }
        }
        bool change=false;
        for(i=0;i<a;i++) if(late[i]<=fs[i]/2.0 && fs[i]!=0){
            if(i+1==c){cout<<"leave\n"; return 0;}
            d=i+1;
            change=true;
            break;
        }
        if(change==false) break;
    }
    cout<<"stay\n";
}
