#include <iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);

    string cadena;
    int shield;
    int cases;
    int i;
    int cambios;
    int damage;
    int shot;
    int caseActual=1;
    cin>>cases;
    while(cases--){
        cin>>shield>>cadena;
        shot=1;
        cambios=0;
        damage=0;
        for(i=0;i<cadena.size();i++){
            if(cadena[i]=='S'){
                cambios++;
                damage+=shot;
            }else{
                shot<<=1;
            }
        }
        if(cambios>shield){
                cout<<"Case #"<<caseActual<<": "<<"IMPOSSIBLE\n";
                caseActual++;
        }else{
            cambios=0;
            while(1){
                damage=0;
                shot=1;
                for(i=0;i<cadena.size();i++){
                    if(cadena[i]=='S'){
                        damage+=shot;
                    }else{
                        shot<<=1;
                    }
                }
                if(damage<=shield) break;
                for(int i=cadena.size()-2;i>=0;i--){
                    if (cadena[i]<cadena[i+1]){
                        swap(cadena[i],cadena[i+1]);
                        cambios++;
                        break;
                    }
                }

            }
            cout<<"Case #"<<caseActual<<": "<<cambios<<'\n';
            caseActual++;
        }

    }

}
