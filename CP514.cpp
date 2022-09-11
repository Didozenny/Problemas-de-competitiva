#include <bits/stdc++.h>

using namespace std;
int main(){
	int N,aux,j=0;
	int permutacion[1000];
	stack<int> stack;
	cin>>N;
	while(N>0){
		cin>>aux;
		while(aux!=0){
			j=0;
			permutacion[0]=aux;
			for (int i = 1; i < N; ++i)//se ingresa la permutacion
			{
				cin>>aux;
				permutacion[i]=aux;
			}
			for (int i = 1; i <= N; ++i)//se ingresan los vagones al stack y se eliminan cuando coincide con la permutacion
			{
				stack.push(i);
				while(stack.size()!=0 and stack.top()==permutacion[j]){
					stack.pop();
					j++;
				}
			}
			if(stack.size()==0) cout<<"Yes"<<endl;//si se logro vaciar el stack es posible
			else{
				cout<<"No"<<endl;
				while(stack.size()!=0){//se vacia el stack para la siguiente ejecucion
					stack.pop();
				}
			} 
			cin>>aux;
		}
		cout<<endl;
		cin>>N;
	}
	return 0;
}