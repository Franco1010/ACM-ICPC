#include<bits/stdc++.h>
using namespace std;
int n,i,j,a,k,m[100000];
string s1,s2;
main(){
cin>>n>>s1>>s2;
for(i=0; i<n; i++){
 if(s1[i]!=s2[i]) a=s1.find(s2[i],i); else continue;
 if(a!=-1)
   for(j=a; j>i; j--){m[k++]=j-1; swap(s1[j],s1[j-1]);}
    else
     {cout<<-1; return 0;}
}
cout<<k<<endl;
for(i=0; i<k; i++)
 cout<<m[i]+1<<" ";
}
