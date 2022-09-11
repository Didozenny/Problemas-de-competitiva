#include<bits/stdc++.h>

using namespace std;


int main(){
	int N;
	vector<int> vecinos;
	cin>>N;
	for(int y=0; y<N;y++){
		int P;
		vecinos.clear();
		cin>>P;
		vecinos.resize(P,0);
		cin.ignore();
		for(int i=0;i<P;i++){
			string s;
			getline(cin,s);
			int v=0;
			for(int j=0;j<s.size();j++){
				if(s[j]==' '){
					v++;
				}
			}
			vecinos[i]=(v+1);
		}
		int min=vecinos[0];
		for(int i=0;i<P;i++){
			if(vecinos[i]<min){
				min=vecinos[i];
			}
		}
		bool primero=true;
		for(int i=0;i<P;i++){
			if(vecinos[i]==min){
				if(!primero)cout<<" ";
				cout<<(i+1);
				primero=false;
			}
		}
		cout<<endl;
	}
	return 0;
} 