/* 
Autor: Vicente Esteban Silva Vera
10763 - Foreign Exchange
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	while(cin>>n and n!=0){
		map<int,vector<int>> vals; 
		for (int i = 0; i < n; ++i)
		{
			int x,y;
			bool found=false;
			cin>>x>>y;
			for (int i = 0; i < vals[y].size(); ++i)
			{
				if(vals[y][i]==x){
					vals[y].erase(vals[y].begin()+i);
					found=true;
					break;
				}
			}
			if(!found)vals[x].push_back(y);
		}
		bool empty=true;
		for (auto const& x : vals)
		{
		    if(x.second.size()!=0){
		    	cout<<"NO"<<endl;
		    	empty=false;
		    	break;
		    }
		}
		if(empty)cout<<"YES"<<endl;
	}

	return 0;
}
