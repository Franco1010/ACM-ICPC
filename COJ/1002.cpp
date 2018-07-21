#include <iostream>
#include <vector>
using namespace std;

int main(){
    int c,d;
    cin>>c;
    while(c--){
        cin>>d;
        int v[d-1][d-1];
        string s[d];
        cout<<1<<endl;
        
        for(int i=0;i<d;i++){
            cin>>s[i];
        }
        cout<<2<<endl;
        for(int i=0;i<d-1;i++){
            for(int j=0;j<d-1;j++){
                v[i].push_back(0);
                cout<<2.1<<endl;
                if(s[i][j]=='.'){
                    if(s[i+1][j]=='.'){
                        v[i][j]++;
                    }
                    if(s[i][j+1]=='.'){
                        v[i][j]++;
                    }
                    if(s[i+1][j+1]=='.'){
                        v[i][j]++;
                    }
                }
                cout<<2.2<<endl;
            }
        }
        cout<<3<<endl;
        for(int i=0;i<d-1;i++){
            for(int j=0;i<d-1;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
