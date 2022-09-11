#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> adj;

vi visited;//ojo con la memoria

vi dist;

void dfs_recursive(int u){
	visited[u] = 1;
	dist[u]=0;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs_recursive(v);
			dist[u]+=dist[v];
			dist[u]++;
		}
	}
	visited[u]=0;
}

int main(){
	int T;
	cin>>T;
	for(int y=0;y<T;y++){
		int N;
		cin>>N;
		visited.clear();
		visited.resize(N);
		adj.clear();
		adj.resize(N);
		dist.clear();
		dist.resize(N,-10);
		for(int i=0;i<N;i++){
			int v,u;
			cin>>v>>u;
			adj[(v-1)].push_back(u-1);
		}
		int max=INT_MIN;
		int pos=-1;
		for(int i=0;i<N;i++){
			if(dist[i]<0)dfs_recursive(i);
			int val=dist[i];
			if(max<val){
				max=val;
				pos=i;
			}
		}
		cout<<"Case "<<y+1<<": "<<pos+1<<endl;
	}
	return 0;
}
