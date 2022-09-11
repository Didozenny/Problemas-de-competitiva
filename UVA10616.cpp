/* 
Autor: Vicente Esteban Silva Vera
10616 - Divisible Group Sums
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

long mx[201][11][40];//indice, size de combinacion y resto que va de -19 a 19

int N[201];

int n,m,d;

long comb(int i,int s, int resto){
	if(mx[i][s][resto+19]!=-1)return mx[i][s][resto+19];//caso ya explorado
	if(s==0 and resto==0){//caso divisible
		return 1;
	}
	if(i==n or s==0){//caso no divisible o no quedan numeros por probar
		return 0;
	}
	int newresto=(N[i]+resto)%d;//obtenemos el resto al tomar el elemento
	long count= comb(i+1,s,resto)+ comb(i+1,s-1,newresto);//sumamos las posibilidades cuando se agrega el indice actual y cuando no se agrega
	mx[i][s][resto+19]=count;//se agrega el valor a los valores calculados
	return count;
}

void setupmx(){//setup de matriz
	for (int i = 0; i <= n; ++i){
		for(int j = 0; j <= 11; j++){
			for(int  k =0; k <= 40; k++){
				mx[i][j][k]=-1;
			}
		}
	}
}

int main(){
	int Q, setnum=1;
	while(cin>>n>>Q and n!=0 and Q!=0){
		setupmx();
		for (int i = 0; i < n; ++i)
		{//introducimos los valores
			int x;
			cin>>x;
			N[i]=x;
		}
		cin>>d>>m;//introducimos valores e imprimos resultados
		cout<<"SET "<<setnum<<":"<<endl;
		cout<<"QUERY 1: "<<comb(0,m,0)<<endl; 
		for (int i = 1; i < Q; ++i)
		{
			setupmx();
			cin>>d>>m;
			cout<<"QUERY "<<i+1<<": "<<comb(0,m,0)<<endl; 
		}
		setnum++;
	}
	
}