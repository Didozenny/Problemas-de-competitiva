#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vector<vi> dominator;

vi visited;//ojo con la memoria
vi visited2;

void dfs_recursive(int u){
	visited[u] = 1;
	for(int v : adj[u]){
		if(!visited[v]) dfs_recursive(v);
	}
}
void dfs_recursive(int u,int i){
	if(u!=i){
		visited2[u] = 1;
		for(int v : adj[u]){
			if(!visited2[v]) dfs_recursive(v,i);
		}
	}
}

int main(){
	int T;
	cin>>T;
	for(int y=0;y<T;y++){
		adj.clear();
		dominator.clear();
		int N;
		cin>>N;
		adj.resize(N);
		dominator.resize(N);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int n;
				cin>>n;
				if(n==1){
					adj[i].push_back(j);
				}
			}
		}
		visited.clear();
		visited.resize(N,0);
		dfs_recursive(0);
		for(int i=0;i<N;i++){
			visited2.clear();
			visited2.resize(N,0);
			dfs_recursive(0,i);
			for(int j=0;j<N;j++){
				if(visited[j]==1 and visited2[j]==0){
					dominator[i].push_back(1);
				}
				else dominator[i].push_back(0);
			}
		}
		cout<<"Case "<<y+1<<":"<<endl;
		for(int i=0;i<N;i++){
			cout<<"+";
			for(int j=0;j<2*N-1;j++)cout<<"-";
			cout<<"+"<<endl<<"|";
			for(int j=0;j<N;j++){
				if(dominator[i][j]==1) cout<<"Y";
				else cout<<"N";
				cout<<"|";
			}
			cout<<endl;
		}
		cout<<"+";
		for(int j=0;j<2*N-1;j++)cout<<"-";
		cout<<"+"<<endl;
	}

	return 0;
}
