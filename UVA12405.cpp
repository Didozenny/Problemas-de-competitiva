/* 
Autor: Vicente Esteban Silva Vera
12405 - Scarecrow
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		int N;
		cin>>N;
		string field;
		cin>>field;//obtenemos string
		int sc=0;
		for(int i=0;i<N;i++){//exploramos la cadena de caracteres
			if(field[i]=='.'){//al encontrar zona a cubrir cubrimos el cuadro siguiente y saltamos dos cuadros
				i+=2;
				sc++;
			}
		}
		cout<<"Case "<<k+1<<": "<<sc<<endl;//imprimimos
	}
	return 0;
}