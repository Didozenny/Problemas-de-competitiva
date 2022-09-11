/* 
Autor: Vicente Esteban Silva Vera
11292 - Dragon of Loowater
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	while(n!=0 and m!=0){
		vector<int> heads;
		vector<int> knights;
		int coins=0;
		int h=0;
		for (int i = 0; i < n; ++i)
		{//cabezas
			int x;
			cin>>x;
			heads.push_back(x);
		}
		for (int i = 0; i < m; ++i)
		{//guerreros
			int x;
			cin>>x;
			knights.push_back(x);
		}
		sort(heads.begin(),heads.end());//sort de valores
		sort(knights.begin(),knights.end());
		for (int i = 0; i < m; ++i)
		{//vamos con los guerreros menores a mayores con cabezas correspondientes al avanzar
			if(knights[i]>=heads[h]){
				coins+=knights[i];//dinero
				h++;//cabeza cortada
			}
			if(h==n)break;
		}
		if(h==n)cout<<coins<<endl;
		else cout<<"Loowater is doomed!"<<endl;
		cin>>n>>m;
	}
	return 0;
}