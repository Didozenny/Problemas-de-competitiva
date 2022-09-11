/* 
Autor: Vicente Esteban Silva Vera
10819 - Trouble of 13-Dots
Usuario: Didozenny ID: 1209597
Autoría propia con fuerte inspiracion en el ejercicio de pesos pasado en clases
*/
#include <bits/stdc++.h>

using namespace std;

int mx[101][10001]= {};
vector<pair<int,int>> vestidos;

int maxval(int m,int n, int i, int spend){
	if((spend>m and  m<1800) or (spend>m+200 and m>1800)){//casos en el que el dinero no es suficiente
		return -99999;
	}
	if(i==n and spend<=2000 and spend>m){//caso en el que no se alcanza a aplicar +200 al dinero inicial
		return -99999;
	}
	if(i==n) return 0;//se compro todo en esta rama de recursion
	if(mx[i][spend]!=-1){
		return mx[i][spend];//ya se calculo este valor
	}
	else{
		mx[i][spend]=max(maxval(m,n,i+1,spend),maxval(m,n,i+1,spend+vestidos[i].first)+vestidos[i].second);//se toma el mayor valor entre la recursion obtenida al comprar este vestido o no comprarlo
		return mx[i][spend];
	}
}

void restartmx(int n,int m){//restart de la matriz para almacenar valores
	for (int i = 0; i <= n; ++i)
	{
		for(int j=0;j<=m;j++){
			mx[i][j]=-1;
		}
	}
}



int main(){
	int m,n;
	while(cin>>m>>n){
		restartmx(n,m+200);//setup mx
		for (int i = 0; i < n; ++i)
		{//se obtienen los valores
			int p,f;
			cin>>p>>f;
			vestidos.push_back({p,f});
		}
		cout<<maxval(m,n,0,0)<<endl;//print resultado
		vestidos.clear();//clear setup vestidos
	}
}