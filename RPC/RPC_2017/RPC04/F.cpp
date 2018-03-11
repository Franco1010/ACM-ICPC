
#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    int c,f,l,i,j;
    string s;
    cin>>c;
    while(c--){
        cin>>s>>f;
        l=s.size();
        vector<int>v(l,1);
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if((s[i]-'a'+f)%26<=(s[j]-'a')%26){
                    if(v[j]<v[i]+1) v[j]=v[i]+1;
                }
            }
        }
        sort(v.rbegin(), v.rend());
        cout<<v[0]<<'\n';
    }
    return 0;
}
