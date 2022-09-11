/* 
Autor: Vicente Esteban Silva Vera
Se utilizo algoritmo de bellman ford y el conocimiento de que luego de
n-1 iteraciones ninguna distancia debe cambiar a menos de que exista un
ciclo negativo
558 Wormholes
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

struct edge{
	int src,dest,weight;
};

int main(){
	int c;
	cin>>c;
	for(int k=0;k<c;++k){
		int n,m;
		cin>>n>>m;
		struct edge edges[m];//creamos arreglo de edges
		vector<int> dist(n,INT_MAX);//creamos vector de distancias
		dist[0] = 0;
		for (int i = 0; i < m; ++i){//almacenamos todos los edges
			int a,b,w;
			cin>>a>>b>>w;
			edges[i].src = a;
			edges[i].dest = b;
			edges[i].weight = w;
		}
		for (int i = 0; i < n-1; ++i){//aplicamos algoritmo de Bellman Ford
			for (int j = 0; j < m; ++j){
				int a = edges[j].src;
				int b = edges[j].dest;
				int w = edges[j].weight;
				if(dist[a] != INT_MAX and dist[b] > dist[a] + w)
					dist[b] = dist[a] + w;
			}
		}
		bool Ncycle = false;
		for (int j = 0; j < m; ++j){//revisamos si luego de aplicar bellman ford por n-1 iteraciones alguna distancia cambia
			int a = edges[j].src;
			int b = edges[j].dest;
			int w = edges[j].weight;
			if(dist[a] != INT_MAX and dist[b] > dist[a] + w){
				Ncycle = true;
				break;
			}
		}
		if(Ncycle)cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
}