#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> breaks;

vector<int> solution;

int error[5]={};

void eval(vector<int> v){
	int time=0;
	int b=0;
	if(solution.empty()){
		for(int j=0;j<v.size();j++){
			time+=v[j];
			if(j+1<v.size() and time+v[j+1]<breaks[b].first){//alcanza otro programa antes del corte
				continue;
			}
			if(time>breaks[b].first){//solucion invalida
				for(int k=0;k<5;k++)error[k]=0;
				return;
			}
			else if(time<=breaks[b].first){
				error[breaks[b].second-1]+=(breaks[b].first-time);
				time=breaks[b].first;
				b++;
			}
			if(b==breaks.size()){
				for(int k=0;k<v.size();k++){
					solution.push_back(v[k]);
				}
			}
		}
	}
	else{
		for(int j=0;j<v.size();j++){
			time+=v[j];
			int erroraux[5]={};
			if(j+1<v.size() and time+v[j+1]<breaks[b].first){//alcanza otro programa antes del corte
				continue;
			}
			if(time>breaks[b].first){//solucion invalida
				break;
			}
			else if(time<=breaks[b].first){
				erroraux[breaks[b].second-1]+=(breaks[b].first-time);
				time=breaks[b].first;
				b++;
			}
			if(b==breaks.size()){
				for(int k=0;k<5;k++){
					if(error[k]==erroraux[k])continue;
					else if(error[k]>error[k]){//nueva mejor solucion
						solution.clear();
						for(int k=0;k<v.size();k++)solution.push_back(v[k]); 
						for(int k=0;k<5;k++)error[k]=erroraux[k];
					}
					break;
				}
			}
		}

	}

}

void permute(vector<int> v, int l, int r){
	int i;
	if(l==r){
		eval(v);
	}
	else{
		for(i=l;i<=r;i++){
			swap(v[l],v[i]);
			permute(v,l+1,r);
			swap(v[l],v[i]);
		}
	}
}

int main(){
	int p=0;
	while(cin>>p and p!=0){
		breaks.clear();
		solution.clear();
		vector<int> values;
		for(int i=0;i<p;i++){
			int x;
			cin>>x;
			values.push_back(x);
		}
		int alig=0;
		cin>>alig;
		for(int i=0;i<alig;i++){
			int x,y;
			cin>>x>>y;
			breaks.push_back({y,x});
		}
		sort(breaks.begin(),breaks.end());
		permute(values,0,values.size()-1);
		for(int i=0;i<solution.size();i++){
			cout<<solution[i]<<" ";
		}
		cout<<endl;
		for (int i = 0; i < 5; ++i)
		{
			cout<<error[i]<<" "<<endl;
		}
	}
	return 0;
}