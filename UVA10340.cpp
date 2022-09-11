/* 
Autor: Vicente Esteban Silva Vera
10340 All in All
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include<bits/stdc++.h>

using namespace std;


int main(){
	string str, substr;
	while(cin>>substr){
		cin>>str;
		if(substr.size()>substr.size()){
			cout<<"No"<<endl;
			continue;
		}
		int cont=0;
		for (int i = 0; i < str.size(); ++i)
		{
			if(str[i]==substr[cont])cont++;
			if(cont==substr.size()){
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(cont==substr.size())continue;
		cout<<"No"<<endl;
	}
	return 0;
}