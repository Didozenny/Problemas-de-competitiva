/* 
Autor: Vicente Esteban Silva Vera
10684 - The jackpot
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int  maxval(vector<int> vals,int start){//tomamos la suma de los valores de izquierda a derecha comenzando por el punto de inicio y registramos el mayor valor obtenido
	int max=INT_MIN;
	int  sum=0;
	for(int i=start;i<vals.size();i++){
		sum+=vals[i];
		if(sum>max){
			max=sum;
		}
	}
	return max;
}

int main(){
	int max=INT_MIN;
	vector<int> vals;
	int x;
	while(cin>>x and x!=0){//ingresamos cantidad de valores
		for (int i = 0; i < x; ++i)//almacenamos los valores
		{
			int k;
			cin>>k;
			vals.push_back(k);
		}
		for (int i = 0; i < vals.size(); ++i)//aplicamos maxval con distintos puntos de inicio y almacenamos el valor mayor
		{
			int mv=maxval(vals,i);
			if(max<mv){
				max=mv;
			}
		}
		if(max>0)cout<<"The maximum winning streak is "<<max<<"."<<endl;//imprimos resultado
		else cout<<"Losing streak."<<endl;
		max=INT_MIN;//setup para proxima iteracion
		vals.clear();
	}
}