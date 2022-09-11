#include <bits/stdc++.h>
using namespace std;

int main(){
	string line;
	int tests,sum=0;
	cin>>tests;
	cin.ignore();
	getline(cin,line);
	while(tests--){
		map<string,int> tree;
		sum=0;
		while(getline(cin,line) and line!=""){
			tree[line]++;
			sum++;
		}
		for(map<string,int>::iterator it=tree.begin();it!=tree.end();it++){
			double result;
			result=((double)it->second)/sum*100;
			cout<<it->first<<" "<<fixed<<setprecision(4)<<result<<endl;
		}
		if(tests!=0)cout<<endl;
	}
	return 0;
}