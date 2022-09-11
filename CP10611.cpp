#include <bits/stdc++.h>

using namespace std;
int main(){
	long int n,q,aux,amay=0,amen=0;
	cin>>n;
	long int *N= new long int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>aux;
		N[i]=aux;
	}
	cin>>q;
	long int *Q= new long int[q];
	for (int i = 0; i < q; ++i)
	{
		cin>>aux;
		Q[i]=aux;
	}
	for (int i = 0; i < q; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(N[j]<Q[i]){//buscamos el mayor valor menor que la altura
				if(amen==0){
					amen=N[j];
				}
				else if(N[j]>amen){
					amen=N[j];
				}
			}
			else if(N[j]>Q[i]){//buscamos el menor valor mayor que la altura
				if(amay==0){
					amay=N[j];
				}
				else if(N[j]<amay){
					amay=N[j];
				}
			}
		}
		if(amen!=0){
			cout<<amen<<" ";
			amen=0;
		}
		else cout<<"X ";
		if(amay!=0){
			cout<<amay<<endl;
			amay=0;
		}
		else cout<<"x"<<endl;
	}
	return 0;
}