/* 
Autor: Vicente Esteban Silva Vera
11264 - Coin Collector
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;//test cases
	while(T--){
		int n;
		cin>>n;//numeros de tipo de moneda
		vector<int> vals;
		for (int i = 0; i < n; ++i)
		{//tipos de moneda
			int x;
			cin>>x;
			vals.push_back(x);
		}
		int sum=vals[0];
		int cont=1;
		for (int i = 1; i < n; ++i)
		{
			bool fullnumber=false;//booleano que identifica si la suma es igual a un numero de moneda mayor
			if((sum+vals[i])/vals[i]==1 and (sum+vals[i])%vals[i]>0){//se prueba que la moneda a agregar no se reste dos veces
				for (int j = i+1; j < n; ++j)
				{
					if((sum+vals[i])>=vals[j])fullnumber=true;
				}
				if(!fullnumber){//en caso de que la suma no sea mayor que una moneda mayor se agrega a la cantidad de monedas y aumenta el valor acumulado
					sum+=vals[i];
					cont++;
				}
			}
		}
		cout<<cont<<endl;
	}
	return 0;
}