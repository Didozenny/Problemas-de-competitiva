/* 
Autor: Vicente Esteban Silva Vera
12210 - A Match Making Problem
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int c=1;
	int B,S;
	cin>>B>>S;
	while(B!=0 and S!=0){
		int dif=B-S;//diferencia entre B y S
		int min=INT_MAX;
		for (int i = 0; i < B; ++i)
		{//B con minimo de edad
			int x;
			cin>>x;
			if(x<min){
				min=x;
			}
		}
		for (int i = 0; i < S; ++i)
		{
			int x;
			cin>>x;
		}
		if(dif<=0)cout<<"Case "<<c<<": 0"<<endl;//todos tienen pareja
		else cout<<"Case "<<c<<": "<<dif<<" "<<min<<endl;//existe diferencia
		c++;
		cin>>B>>S;
	}
	return 0;
}