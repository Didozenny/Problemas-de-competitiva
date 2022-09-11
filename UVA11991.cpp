#include<bits/stdc++.h>

using namespace std;


int main(){
	vector<vector<int>> adj;
	int n;
	while(cin>>n){
		adj.clear();
		adj.resize(1000001);
		int m;
		cin>>m;
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			adj[num].push_back(i);
		}
		for(int i=0;i<m;i++){
			int k,v;
			cin>>k>>v;
			if(adj[v].size()>=k){
				cout<<adj[v][k-1]+1<<endl;
			}
			else{
				cout<<"0"<<endl;
			}
		}
	}
	return 0;
} 