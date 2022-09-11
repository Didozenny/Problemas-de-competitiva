/* 
Autor: Vicente Esteban Silva Vera
11100 - The Trip, 2007
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin>>n and n!=0){
		vector<int> bags;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			bags.push_back(x);
		}
		sort(bags.begin(),bags.end());//ordenamos elementos
		int numrep=bags[0];
		int maxcount=0, count=0;
		for (int i = 0; i < n; ++i)//obtenemos la cantidad que se repite la bolsa mas repetida
		{
			if(bags[i]==numrep){//aumento contador
				count++;
			}
			else{
				if(count>maxcount)maxcount=count;
				numrep=bags[i];
				count=1;
			}
		}
		if(count>maxcount)maxcount=count;
		cout<<maxcount<<endl;//se imprime cantidad maxima
		for (int i = 0; i < maxcount; ++i)//la 
		{
			for(int j=i; j<n; j+=maxcount){//se imprime resultado, como maxcount es el mayor numero de repeticiones todos los elementos en una linea son distintos
				cout<<bags[j];
				if(j+maxcount<n)cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}