#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(cin>>N,N){
		multiset<long int> ms;
		long long int sum=0;
		long int valor;
		multiset<long int>::iterator it1, it2;
		for (int i = 0; i < N; ++i)
		{
			int aux;
			cin>>aux;
			ms.insert(aux);
		}
		while(ms.size()!=1){
			it1=ms.begin();
			it2=(it1++);
			valor=(*it1+*it2);
			ms.erase(it1);
			ms.erase(it2);
			ms.insert(valor);
			sum+=valor;
		}
		cout<<sum<<endl;
	}
}