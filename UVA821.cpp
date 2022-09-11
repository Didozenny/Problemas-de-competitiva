/* 
Autor: Vicente Esteban Silva Vera
821 - Page Hopping
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int dist[101];

vector<int> adylist[101];


void bfs(int src){
	dist[src]=0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adylist[v].size(); ++i)
		{
			int val = adylist[v][i];
			if(dist[val] == -1){
				dist[val] = dist[v]+1;
				q.push(val);
			}
		}
	}
}

 
int main(){
	int caseN = 0;
	cout << std::fixed;
    cout << std::setprecision(3);
	int a,b;
	cin>>a>>b;
	while(a !=0 or b !=0){
		caseN +=1;
		unordered_set<int> numbers;
		numbers.insert(a);
		numbers.insert(b);
		for (int i = 0; i < 101; ++i)adylist[i].clear();//reseteamos matriz
		while(a !=0 or b !=0){//creamos matriz de adyacencia
			//cout<<"VALS DE A Y B:"<<a<<" "<<b<<endl;
			numbers.insert(a);
			numbers.insert(b);
			adylist[a].push_back(b);
			cin>>a>>b;
		}
		int sum = 0;
		unordered_set<int>::iterator itr;
		for (itr = numbers.begin();itr != numbers.end(); itr++){//aplicamos bds desde cada elemento
			memset(dist,-1,sizeof(dist));
    		bfs(*itr);
    		unordered_set<int>::iterator itr2;
    		//cout<<"DISTANCIAS DE "<<*itr<<endl;
    		for (itr2 = numbers.begin();itr2 != numbers.end(); itr2++){//sumamos las distancias obtenidas
    			//cout<<*itr2<<": "<<dist[*itr2]<<" ";
    			sum+=dist[*itr2];
    		}
    		//cout<<endl<<*itr<<endl;
		}
		int permutations = numbers.size()*(numbers.size()-1);
		//cout<<sum<<endl<<permutations<<endl;
		double answer = double(sum)/permutations;//obtenemos resultado
		cout<<"Case "<<caseN<<": average length between pages = "<<answer<<" clicks"<<endl;
		cin>>a>>b;
	}
	return 0;
}