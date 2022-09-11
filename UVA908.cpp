/* 
Autor: Vicente Esteban Silva Vera
//se utilizo Disjoin set para encontrar ciclos presentado en el video https://www.youtube.com/watch?v=eTaWFhPXPz4
908 - Re-connecting Computer Sites
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> parents;//vector que almacena el padre de de los nodos para asi detectar si estan en el mismo set
int find(int v){//encontramos el padre de v
	if(parents[v]==-1)return v;
	return find(parents[v]);

}

void join(int from,int to){//unimos los dos sets
	from=find(from);
	to=find(to);
	parents[from]=to;
}

bool isCycle(vector<pair<int,pair<int,int>>>& edgelist){//revisamos si existe un ciclo
	fill(parents.begin(),parents.end(),-1);//reiniciamos lista de padres
	for(auto p:edgelist){
		int from=find(p.second.first);
		int to=find(p.second.second);
		if(from==to)return true;//tienen los mismos padres lo que significa que hay un ciclo
		join(from,to);//agregamos la arista a los sets
	}
	return false;
}
int main(){
	int N,K,M;
	int valant=0,newval=0;
	vector<pair<int,pair<int,int>>> aristas;
	vector<pair<int,pair<int,int>>> red;
	bool firstcase=true;
	while(cin>>N){
		if(!firstcase)cout<<endl;
		else firstcase=false;
		parents.resize(N,-1);
		for(int i=0;i<N-1;i++){//obtenemos el valor anterior
			int x,y,z;
			cin>>x>>y>>z;
			valant+=z;
		}
		cin>>K;//cantidad de nuevas conexiones
		for (int i = 0; i < K; ++i)
		{
			int x,y,z;
			cin>>x>>y>>z;
			aristas.push_back({z,{x-1,y-1}});
		}
		cin>>M;//cantidad de conexiones totales
		for (int i = 0; i < M; ++i)
		{
			int x,y,z;
			cin>>x>>y>>z;
			aristas.push_back({z,{x-1,y-1}});
		}
		sort(aristas.begin(),aristas.end());//ordenamos las conexiones por peso
		for (int i = 0; i < aristas.size(); ++i)
		{
			red.push_back(aristas[i]);//agregamos arista
			if(isCycle(red)){//si arista forma ciclo la eliminamos
				red.pop_back();
				continue;
			}
			if(red.size()==N){//tenemos formada la red
				break;
			}

		}
		for (int i = 0; i < red.size(); ++i)
		{//calculamos costo total
			newval+=red[i].first;
		}
		cout<<valant<<endl<<newval<<endl;
		valant=0,newval=0;
		red.clear();
		aristas.clear();
	}
}