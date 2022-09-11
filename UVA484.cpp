#include <bits/stdc++.h>
using namespace std;

int main(){
	int c;
	map<int,int> department;
	vector<int> lista;
	map<int,int>::iterator it;
	while(cin>>c){
		if(department.count(c)==0){
			lista.push_back(c);
		}
		department[c]++;
	}
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<" "<<department[lista[i]]<<endl;
	}
	return 0;
}