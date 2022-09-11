/* 
Autor: Vicente Esteban Silva Vera
787 Maximum Sub-sequence Product
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

long long  maxval(vector<int> vals,int start){
	long long max=INT_MIN;
	long long  mult=1;
	for(int i=start;i<vals.size();i++){
		mult*=vals[i];
		if(mult>max){
			max=mult;
		}
	}
	return max;
}

int main(){
	long long max=INT_MIN;
	vector<int> vals;
	int x;
	while(cin>>x){
		vals.push_back(x);
		while(cin>>x and x!=-999999){
			vals.push_back(x);
		}
		for (int i = 0; i < vals.size(); ++i)
		{
			long long mv=maxval(vals,i);
			if(max<mv){
				max=mv;
			}
		}
		cout<<max<<endl;
		max=INT_MIN;
		vals.clear();
	}
}