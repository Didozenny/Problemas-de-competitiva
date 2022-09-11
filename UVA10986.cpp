#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj; 
vi dist;

void dijksrta(int s){
	priority_queue<ii, vii, greater<ii>> pq;
	dist[s]=0;
	pq.push({0,s});
	//comenzamos a recorrer
	while(!pq.empty()){
		int u_dist=pq.top().first;
		int u_vertex=pq.top().second;
		pq.pop();
		//lazy deletion
		if(u_dist > dist[u_vertex])  continue;

		for(ii it: adj[u_vertex]){
			int v_vertex=it.first;
			int v_dist=it.second;
			//relajacion
			//si el peso del camino actual es mejor que el anterior
			if(u_dist + v_dist>= dist[v_vertex]) continue; 
			dist[v_vertex]=u_dist+v_dist;
			pq.push({dist[v_vertex],v_vertex});
		}
	}
}

int main(){
	int C;
	cin>>C;
	for(int y=0;y<C;y++){
		adj.clear();
		dist.clear();
		int n,m,S,T;
		cin>>n>>m>>S>>T;
		adj.resize(n);
		dist.resize(n, INT_MAX);  
		for(int i=0;i<m;i++){
			int s1,s2,w;
			cin>>s1>>s2>>w;
			adj[s1].push_back({s2,w});
			adj[s2].push_back({s1,w});
		}
		dijksrta(S);
		if(dist[T]==INT_MAX)cout<<"Case #"<<y+1<<": "<<"unreachable"<<endl;
		else cout<<"Case #"<<y+1<<": "<<dist[T]<<endl;
	}
}