#include<bits/stdc++.h>

using namespace std;

map<string,vector<string>> adj;

map<string,int> dist;

void bfs(string s){
	queue<string> q;
	q.push(s);
	dist[s]=0;

	while(!q.empty()){
		string u=q.front();
		q.pop();
		for(string v : adj[u]){
			if(dist[v]==INT_MAX){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}

bool comparar(string s1, string s2){
	if(s1.size()!=s2.size())return false;
	int dif=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i])dif++;
	}
	if(dif==1)return true;
	return false;
}


int main(){
	vector<string> list;
	string basura;
	int N;
	cin>>N;
	getline(cin,basura);
	for(int y=0;y<N;y++){
		string s;
		getline(cin,s);
		adj.clear();
		dist.clear();
		while(s!="*"){
			list.push_back(s);
			getline(cin,s);
		}
		for(int i=0;i<list.size();i++){
			dist[list[i]]=INT_MAX;
		}
		for(int i=0;i<list.size();i++){
			for(int j=i+1;j<list.size();j++){
				if(comparar(list[i],list[j])){
					adj[list[i]].push_back(list[j]);
					adj[list[j]].push_back(list[i]);
				}
			}
		}
		string start, end,line;
		while(getline(cin,line)){
			if(line=="")break;
			stringstream ss(line);
			ss>>start>>end;
			dist.clear();
			for(int i=0;i<list.size();i++){
				dist[list[i]]=INT_MAX;
			}
			bfs(start);
			cout<<start<<" "<<end<<" "<<dist[end]<<endl;
		}
		if(y!=N-1)cout<<endl;
	}
	return 0;
} 