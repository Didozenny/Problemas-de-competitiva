/* 
Autor: Vicente Esteban Silva Vera
10020 Minimal coverage
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include<bits/stdc++.h>

using namespace std;


int main(){
	int c;
	string str;
	cin>>c;
	bool first=true;
	while(c--){
		getline(cin,str);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if(first)first=false;
		else cout<<endl;
		int M;
		cin>>M;
		vector<pair<int,int>> lines, res;
		int Li,Ri;
		while(cin>>Li>>Ri and (Li!=0 or Ri!=0)){
			lines.push_back({Li,Ri});
		}
		sort(lines.begin(),lines.end());
		if(lines[0].first>0){//no hay nodo de inicio
			cout<<"0"<<endl;
			continue;
		}
		for (int i = 0; i < lines.size(); ++i)
		{
			if(lines[i].first<=0){//busca de linea de inicio
				if(lines[i].second<=0){//linea inutil
					continue;
				}
				if(res.size()==1 and res[0].second<lines[i].second){//ya hay una linea de inicio y se reemplaza
					res.pop_back();
					res.push_back(lines[i]);
				}
				else if(res.size()==0)res.push_back(lines[i]);//primer posible linea de inicio
				/*if(res[res.size()-1].second>=M){
					break;
				}*/
			}
			else if(res.size()==0 or res[res.size()-1].second>=M)break;//no se encontro primera linea valida
			else{
				if(lines[i].first>res[res.size()-1].second)break;//hay un gap entre lineas
				if(lines[i].second>res[(res.size()-1)].second){//la linea nos hace llegar mas lejos
					while(res.size()>=2 and res[res.size()-2].second>=lines[i].first)res.pop_back();//eliminamos lineas obsoletas
					res.push_back(lines[i]);//agregamos linea
				}
			}
		}
		while(res.size()>=2 and res[res.size()-2].second>=M)res.pop_back();
		if(res.size()>0 and res[res.size()-1].second>=M){
			cout<<res.size()<<endl;
			for (int i = 0; i < res.size(); ++i)
			{
				cout<<res[i].first<<" "<<res[i].second<<endl;
			}
		}
		else cout<<"0"<<endl;
	}
	


	return 0;
}