#include <bits/stdc++.h>

using namespace std;
int main(){
	int valores[3000], resultados[3000];
	int n;
	bool jolly,esta;
	while(cin>>n){
		cin>>valores[0];
		jolly=true;
		esta=true;
		for(int i=1;i<n;i++){//ingreso valores y obteno diferencias
			cin>>valores[i];
			resultados[i-1]=abs(valores[i-1]-valores[i]);
		}
		for (int i = 1; i < n; ++i)//verificamos que los valores que se buscan esten
		{
			esta=false;
			for (int j = 0; j < n-1; ++j)
			{
				if(resultados[j]==i){
					esta=true;
				}
			}
			if(!esta){
				jolly=false;
			}
		}
		if(jolly)cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
	}
	return 0;
}