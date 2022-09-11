#include <bits/stdc++.h>

using namespace std;

vector<int> tracks;

int error=INT_MAX,N;

vector<int> solution;

void subsets(vector<int> vec,int i){//armamos todos los subset de forma recursiva
	if(tracks.size()==i){//subset formado por completo
		int sum=0;
		for (int i = 0; i < vec.size(); ++i)
		{//se suman los valores
			sum+=vec[i];
		}
		if(N-sum>=0 and N-sum<error){//si la nueva solucion es mejor que la anterior se reemplaza y actualiza el error
			error=N-sum;
			solution.clear();
			for (int i = 0; i < vec.size(); ++i)
			{
				solution.push_back(vec[i]);
			}
		}
	}
	else{//generacion subset recursivo
		subsets(vec,i+1);
		vec.push_back(tracks[i]);
		subsets(vec,i+1);
	}
}

int main(){
	while(cin>>N){//cantidad de tiempo
		tracks.clear();//reseteamos variables globales
		solution.clear();
		error=INT_MAX;
		int t;
		cin>>t;
		for (int i = 0; i < t; ++i)
		{//lista de tracks
			int x;
			cin>>x;
			tracks.push_back(x);
		}
		vector<int> set;
		subsets(set,0);//generamos y evaluamos subsets
		int sum=0;
		for (int i = 0; i < solution.size(); ++i)
		{//imprimimos solucion
			cout<<solution[i]<<" ";
			sum+=solution[i];
		}
		cout<<"sum:"<<sum<<endl;//suma
	}
	return 0;
}