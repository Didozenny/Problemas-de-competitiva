/* 
Autor: Vicente Esteban Silva Vera
410 Station Balance
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include<bits/stdc++.h>

using namespace std;


int main(){
	std::cout<<std::fixed;
	std::cout << std::setprecision(5);
	int C,set=0;
	while(cin>>C){
		int S;
		cin>>S;
		vector<int> w;
		vector<vector<int>> CH(5);
		int WC[5]={};
		for (int i = 0; i < S; ++i)//ingresamos pesos
		{
			int weight;
			cin>>weight;
			w.push_back(weight);
		}
		sort(w.begin(),w.end(),greater<int>());//ordenamos al orden en que introducimos
		for (int i = 0; i < w.size(); ++i)
		{
			int min=INT_MAX,minI=-1;
			for (int j = 0; j < C; ++j)//obtenemos chaimber con menor peso
			{
				if(WC[j]<min and CH[j].size()<2){
					min=WC[j];
					minI=j;
				}
			}
			WC[minI]+=w[i];
			CH[minI].push_back(w[i]);
		}
		double media=0;
		for (int i = 0; i < C; ++i)
		{
			media+=WC[i];
		}
		media/=C;
		double imbalance=0;
		for (int i = 0; i < C; ++i)
		{
			imbalance+=abs(WC[i]-media);
		}

		//imprimimos resultados
		set++;
		cout<<"Set #"<<set<<endl;
		for (int i = 0; i < C; ++i)
		{
			cout<<" "<<i<<":";
			for (int j = 0; j < CH[i].size(); ++j)
			{
				cout<<" "<<CH[i][j];
			}
			cout<<endl;
		}
		cout<<"IMBALANCE = "<<imbalance<<endl<<endl;
	}


	return 0;
}