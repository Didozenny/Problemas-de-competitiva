/* 
Autor: Vicente Esteban Silva Vera
1670B Dorms War
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		int size,nsl,cont=0;
		char sl[26];
		vector<int> pos;
		string password;
		cin>>size>>password>>nsl;
		for (int i = 0; i < nsl; ++i)
		{
			cin>>sl[i];
		}
		int count=0,maxdistance=0;
		for (int i = 0; i < size; ++i)
		{
			bool found=false;
			for(int j=0;j<nsl;j++){
				if(password[i]==sl[j])found=true;
			}
			if(found){
				if(maxdistance<count)maxdistance=count;
				count=0;
			}
			count++;
		}
		cout<<maxdistance<<endl;
	}
	return 0;
}