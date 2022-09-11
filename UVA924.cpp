#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> adj;

map<int,int> m;

vi dist;

void bfs(int s){
	queue<int> q;
	q.push(s);
	dist[s]=0;

	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v : adj[u]){
			if(dist[v]==INT_MAX){
				dist[v]=dist[u]+1;
				m[dist[v]]++;
				q.push(v);
			}
		}
	}
}

int main(){
	int E,T;
	cin>>E;
	adj.resize(E);
	for(int k=0;k<E;k++){
		int N;
		cin>>N;
		for(int j=0;j<N;j++){
			int a;
			cin>>a;
			adj[k].push_back(a);
		}
	}
	cin>>T;
	while(T--){
		dist.clear();
		dist.resize(E,INT_MAX);
		m.clear();
		int origin;
		cin>>origin;
		bfs(origin);
		if(m.size()==0){
			cout<<'0'<<endl;
			continue;
		}
		int M,D;
		M=0;
		D=0;
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
			if(it->second>M){
				M=it->second;
				D=it->first;
			}
		}
		cout<<M<<" "<<D<<endl;
	}
	return 0;
}