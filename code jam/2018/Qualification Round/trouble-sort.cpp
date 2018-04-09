#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
cin.tie(0);
ios_base::sync_with_stdio(0);
int casos;
int numCaso=1;
int numElementos;
int posicion;
bool cambio;
vector<int> primero,segundo;

cin>>casos;
while(casos--)
{
    cin>>numElementos;
    primero.clear();
    segundo.clear();
    for(int i=0;i<numElementos;i++){
        cin>>posicion;
        i%2? segundo.push_back(posicion) : primero.push_back(posicion);
    }
    posicion=0;
    sort(primero.begin(),primero.end());
    sort(segundo.begin(),segundo.end());
    cambio=false;

    for(int i=0;i<numElementos/2;i++){
        if(primero[i]>segundo[i]){
            cout<<"Case #"<<numCaso<<": "<<posicion<<'\n';
            cambio=true;
            break;
        }else posicion++;
        if(((primero.size()-1)>i) && (primero[i+1]<segundo[i])){
            cout<<"Case #"<<numCaso<<": "<<posicion<<'\n';
            cambio=true;
            break;
        }else posicion++;
    }
    if(!cambio)
        cout<<"Case #"<<numCaso<<": "<<"OK\n";
    numCaso++;
}

}
