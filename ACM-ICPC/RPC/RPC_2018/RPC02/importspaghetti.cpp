#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;


struct Nodo {
    string nombre;
    vector<long long int>hijos;
};
//map<string,int> mapa;
long long int cont[1000];
Nodo arbol[1000];
long long int posBucle;
long long int tiempo;
void check(long long int i,long long int C){
    if (posBucle==-1) {
        if (arbol[i].hijos.empty()) {
            return;
        }
        cont[i]++;
        if (cont[i]==2) {
            posBucle=i;
            tiempo=C;
        }
        long long int l=arbol[i].hijos.size();
        For(j, 0, l){
            check(arbol[i].hijos[j],C+1);
        }
    }
}

struct lib {
    long long int tiempo,pos;
    bool operator<(const lib &t) const {
        return tiempo < t.tiempo; }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    bool posIgual;
    long long int c,cc,l,pos;
    string aux,nom;
    lib auxLib;
    vector<lib> res;
    cin>>c;
    
    For(i, 0, c){
        cin>>arbol[i].nombre;
    }
    For(i, 0, c){
        cin>>aux;
        //cout<<aux<<"->";
        cin>>cc;
        For(j, 0, cc){
            cin>>aux;
            //cin.get();
            getline(cin,aux);
            aux+=',';
            //cout<<aux<<endl;
            l=aux.size();
            while (!aux.empty()) {
                aux.erase(aux.begin());
                For(k, 0, l){
                    if (aux[k]==',') {
                        nom=aux.substr(0,k);
                        //cout<<nom<<'-';
                        aux.erase(aux.begin(), aux.begin()+k+1);
                        break;
                    }
                }
                For(k, 0, c)
                if (arbol[k].nombre==nom) {
                    pos=k;
                    break;
                }
                arbol[i].hijos.push_back(pos);
            }//cout<<endl;
            
        }
    }
    //cout<<"listo"<<endl;
    
    For(i, 0, c){
        fill(cont, cont+c, 0);
        posBucle=-1;
        posIgual=false;
        check(i,1);
        if (posBucle!=-1) {
            For(j, 0, res.size()){
                if (res[j].pos==posBucle) {
                    posIgual=true;
                }
            }
            if (!posIgual) {
                auxLib.tiempo=tiempo;
                auxLib.pos=posBucle;
                res.push_back(auxLib);
            }
        }
    }
    sort(res.begin(), res.end());
    if (res.empty()) {
        cout<<"SHIP IT\n";
    }else{
        l=res.size();
        For(i, 0, l-1){
            cout<<arbol[res[i].pos].nombre<<' ';
        }
        cout<<arbol[res[l-1].pos].nombre<<'\n';
    }
    return 0;
}

