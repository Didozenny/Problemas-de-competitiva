/* 
Autor: Vicente Esteban Silva Vera
11389 - The Bus Driver Problem
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,d,r;
	cin>>n>>d>>r;//ingreso valores
	while(n!=0 and d!=0 and r!=0){
		vector<int> morn;
		vector<int> even;
		int overtime=0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			morn.push_back(x);
		}
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			even.push_back(x);
		}
		sort(morn.begin(),morn.end());//ordenamos input
		sort(even.begin(),even.end());
		for (int i = 0; i < n; ++i)
		{
			if(morn[i]+even[n-1-i]>d){//sumamos los menores con los mayores sucesivamente
				overtime+=morn[i]+even[n-1-i]-d;
			}
		}
		cout<<overtime*r<<endl;//overtime por valor
		cin>>n>>d>>r;//ingreso valores
	}
	return 0;
}