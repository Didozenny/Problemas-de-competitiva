#include <bits/stdc++.h>
using namespace std;

int main(){
	int c;
	cin>>c;
	while(c--){
		map<signed int,int> list;
		long long int N,M;
		int sum=0;
		cin>>N>>M;
		for (int i = 0; i < N; ++i)
		{
			int aux;
			cin>>aux;
			list[aux]++;
		}
		for (int i = 0; i < M; ++i)
		{
			int aux;
			cin>>aux;
			list[aux]--;
		}
		for(map<signed int,int>::iterator it=list.begin();it!=list.end();it++){
			sum+=abs(it->second);
		}
		cout<<sum<<endl;
	}
	return 0;
}