/* 
Autor: Vicente Esteban Silva Vera
357 - Let Me Count The Ways
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;



long mx[51][30001]={};

long comb(int c, int m){
	if(mx[c][m]!=-1){//ya se encontro valor antes
		return mx[c][m];
	}
	if(m<5 or c==1){//se llego al final de la rama del arbol
		return 1;
	}
	long val=0;
	//tomamos las posibles combinaciones ingresando solo monedas iguales o menores a las monedas ingresadas antes para no repetir combinaciones
	//sumamos las posibilidades de forma iterativa al ingresar cada moneda valida como caso
	if(c==50 and m>=50){
		val+=comb(50,m-50);
	}
	if(c>=25 and m>=25){
		val+=comb(25,m-25);
	}
	if(c>=10 and m>=10){
		val+=comb(10,m-10);
	}
	if(c>=5 and m>=5){
		val+=comb(5,m-5);
	}
	if(c>=5 and m>=5){
		val+=comb(1,m-5);
	}
	mx[c][m]=val;//registramos valor en tabla
	return val;
}

void setupmx(){//setup matriz
	for (int i = 0; i < 51; ++i)
	{
		for(int j=0;j<30001;j++){
			mx[i][j]=-1;
		}
	}
}


int main(){
	long x;
	setupmx();//realizamos setup 1 vez
	while(cin>>x){
		long val=comb(50,x);//obtenemos valor
		if(val==1)cout<<"There is only "<<val<<" way to produce "<<x<<" cents change."<<endl;//imprimimos resultado
		else cout<<"There are "<<val<<" ways to produce "<<x<<" cents change."<<endl;
	}
}