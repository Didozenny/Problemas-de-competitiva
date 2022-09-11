#include <bits/stdc++.h>

using namespace std;

int m[8][8];

int minim=INT_MAX;

int values[]={0,1,2,3,4,5,6,7};//vector utilizado para generar las posibilidades

void permute(int n){//genera todas las posibilidades y las evalua
	int sum=0;
	do{
		for (int i = 0; i < n; ++i)
		{
			sum+=m[values[i]][i];//se exploran todas las posibles jugadas, utilizando las distintas posibles distribuciones de las filas
		}
		if(sum<minim){//evaluamos solucion, como quien
			minim=sum;
		}
		sum=0;
	}while(next_permutation(values,values+n));//utilizamos next permutation para generar todas las posiblidades
	for (int i = 0; i < n; ++i)
	{
		sum+=m[values[i]][i];
	}
	if(sum<minim){
		minim=sum;
	}
	sort(values,values+7);//hacemos sort de values, para luego poder utilizar next_permutation de forma efectiva
} 

int main(){
	int t;
	cin>>t;
	while(t--){//test cases
		int n;
		cin>>n;
		for(int i=0;i<n;i++){//armamos la matriz
			for (int j = 0; j < n; ++j){
				cin>>m[i][j];
			}
		}
		permute(n);
		cout<<minim<<endl;//imprimimos resultados
		minim=INT_MAX;//reseteamos valor
	}
	return 0;
}