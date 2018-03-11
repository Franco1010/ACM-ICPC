#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(NULL);
	int B,N,suma,aux,i;
	while(true)
	{
		cin>>B>>N;
		suma=0;
		if(B==0 && N==0) break;
		for(i=0;i<B;i++)
		{
			cin>>aux;
			suma+=aux;
		}
		cout<<N/suma<<'\n';
	}
	return 0;
}
