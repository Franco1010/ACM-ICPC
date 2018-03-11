#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
#define MOD 1000000007


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long int c,cont=0,sum;
    bool r;
    string s;
    vector<int>colors;
    cin>>c;
    while (c--) {
        cin>>s;
        if (s=="red") {
            cont++;
        }
        else if (s=="yellow") colors.push_back(2);
        else if(s=="green") colors.push_back(3);
        else if(s=="brown") colors.push_back(4);
        else if(s=="blue") colors.push_back(5);
        else if(s=="pink") colors.push_back(6);
        else if(s=="black") colors.push_back(7);
    }
    sort(colors.begin(), colors.end());
    sum=0;
    
    if (colors.empty()) {
        r=false;
    }else r=true;
    
    while (true) {
        if (r) {
            if (!colors.empty()) {
                sum+=colors[0];
                colors.erase(colors.begin());
                if (cont>0) {
                    colors.insert(colors.begin(), colors.at(colors.size()-1));
                    r=false;
                }
            }else break;
        }else{
            r=true;
            if (cont>0) {
                cont--;
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

