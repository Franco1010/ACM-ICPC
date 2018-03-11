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
double tiempos[2][501];
//string nombres[501];

struct Runn {
    double tiempo;
    double ini;
    string nombre;
    bool operator<(const Runn &t) const {
        return tiempo < t.tiempo; }
};
vector<Runn> runners;
//vector<Runn> run2;
vector<Runn> posible;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    Runn aux;
    long long int c;
    double M=1000000,sum=0;
    //double tT[4];
    //string tN[4];
    cin>>c;
    For(i, 0, c){
        cin>>aux.nombre;
        cin>>tiempos[0][i];// 1st leg
        cin>>tiempos[1][i];// any leg
        
        aux.ini=tiempos[0][i];
        aux.tiempo=tiempos[1][i];
        runners.push_back(aux);
    }
    sort(runners.begin(), runners.end());
    For(i, 0, c){
        sum=0;
        /*while (!run2.empty()) {
         run2.erase(run2.begin());
         }
         For(j, 0, c){
         run2.push_back(runners[j]);
         }*/
        sum+=runners[i].ini;
        /* string auxS=runners[posInicial].nombre;
         aux.tiempo=tiempos[0][posInicial];*/
        aux.nombre=runners[i].nombre;
        aux.tiempo=runners[i].tiempo;
        aux.ini=runners[i].ini;
        
        runners.erase(runners.begin()+i);
        //sort(run2.begin(), run2.end());
        For(i, 0, 3){
            sum+=runners[i].tiempo;
        }
        if (sum<M) {
            M=sum;
            //posible.clear();
            while (!posible.empty()) {
                posible.erase(posible.begin());
            }
            posible.push_back(aux);
            For(i, 0, 3){
                posible.push_back(runners[i]);
            }
        }
        runners.insert(runners.begin()+i, aux);
        //runners.push_back(aux);
    }
    
    
    
    
    cout<<M<<'\n';
    For(i, 0, 4){
        cout<<posible[i].nombre<<'\n';
    }
    
    
    return 0;
}

