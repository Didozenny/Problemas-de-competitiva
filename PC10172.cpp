#include <bits/stdc++.h>

using namespace std;
int main(){
	queue<int> B[100];
	stack<int> carro;
	int SET,N,S,Q,lugar,tiempo,total;
	cin>>SET;
	for(int k=0;k<SET;k++){
		lugar=0;
		total=0;
		tiempo=0;
		cin>>N>>S>>Q;
		for (int i = 0; i < N; ++i)//se ingresan las cargas a las estaciones y se obtiene total
		{
			int n;
			cin>>n;
			total+=n;
			for(int j=0;j<n;j++){
				int aux;
				cin>>aux;
				B[i].push(aux-1);
			}
		}
		while(total>0){
			if(lugar==N){
				lugar=0;
			}
			while(!carro.empty() and carro.top()==lugar){//descarga en A
				carro.pop();
				total--;
				tiempo++;
			}
			while(!carro.empty() and B[lugar].size()<Q){//descarga en B
				if(carro.top()==lugar){
					carro.pop();
					total--;
				}
				else{
					B[lugar].push(carro.top());
					carro.pop();
				}
				tiempo++;
			}
			while(!carro.empty() and carro.top()==lugar){//descarga en A
				carro.pop();
				total--;
				tiempo++;
			}
			while(carro.size()<S and !B[lugar].empty()){//se carga al carro desde B
				carro.push(B[lugar].front());
				B[lugar].pop();
				tiempo++;
			}
			lugar++;
			tiempo+=2;
		}
		cout<<tiempo-2<<endl;
	}
	return 0;
}