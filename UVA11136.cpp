#include <bits/stdc++.h>
using namespace std;

int main(){
	int c;
	while(cin>>c,c){
		long long int sum=0;
		int tickets,aux;
		multiset<int> ms;
		multiset<int>::iterator it1,it2;
		while(c--){
			cin>>tickets;
			while(tickets--){
				cin>>aux;
				ms.insert(aux);
			}
			it1=ms.begin();
			it2=ms.end();
			it2--;
			sum+=(*it2-*it1);
			ms.erase(it1);
			ms.erase(it2);
		}
		cout<<sum<<endl;
	}
	return 0;
}