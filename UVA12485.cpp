/* 
Autor: Vicente Esteban Silva Vera
12485 - Perfect Choir
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	while(cin>>N){
		int sum=0,diff=0;
		vector<int> notes;
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin>>x;
			notes.push_back(x);
		}
		sum=accumulate(notes.begin(),notes.end(),0);//obtenemos la suma de los valores
		if(sum%notes.size()!=0){//si el promedio no es entero, es imposible llegar a la linea en la que coinciden
			cout<<"-1"<<endl;
			continue;
		}
		for (int i = 0; i < notes.size(); ++i)//obtenemos diferencia entre las notas y el valor objetivo
		{
			diff+=abs(int(sum/notes.size())-notes[i]);
		}
		if(diff%2!=0){//no se puede llegar
			cout<<"-1"<<endl;
			continue;
		}
		cout<<diff/2+1<<endl;//cantidad de notas necesarias es la cantidad de veces que hay que cambiar +1
	}
	return 0;
}