#include <bits/stdc++.h>

using namespace std;
int main(){
	queue<pair<int,int>> left,right;
	int tiempo=0,c,lugar=0;
	long int n,m,t;
	cin>>c;
	for(int k=0;k<c;k++){
		tiempo=0;
		lugar=0;
		vector<pair<int,int>> sol;
		cin>>n>>t>>m;
		for (int i = 0; i < m; ++i)
		{
			string lado;
			int hora;
			cin>>hora>>lado;
			if(lado=="left")left.push({i,hora});
			else right.push({i,hora});
		}
		while(right.size()!=0 or left.size()!=0){
			if(lugar==0){//left
				if(left.size()!=0 and left.front().second<=tiempo){//hay autos en el lado correspondiente
					for (int i = 0; i < n; ++i)
					{
						if(left.size()!=0 and left.front().second<=tiempo){
							pair<int,int> aux;
							aux={left.front().first,tiempo+t};
							sol.push_back(aux);
							left.pop();
						}
					}
					tiempo+=t;
					lugar=1;
				}
				else if(left.size()!=0 and right.size()!=0 and left.front().second<=right.front().second){//los autos llegan antes por la izquierda
					tiempo=left.front().second;
				}
				else if(left.size()!=0 and right.size()!=0){//los autos llegan antes por la derecha
					tiempo=max(right.front().second,tiempo);
					tiempo+=t;
					lugar=1;
				}
				else if(left.size()==0){//no llegaran mas autos por la izquierda
					tiempo=max(tiempo,right.front().second);
					tiempo+=t;
					lugar=1;
				}
				else if(right.size()==0){//no llegaran mas autos por la derecha
					tiempo=left.front().second;
				}
			}
			else{//right
				if(right.size()!=0 and right.front().second<=tiempo){//hay autos en el lado correspondiente
					for (int i = 0; i < n; ++i)
					{
						if(right.size()!=0 and right.front().second<=tiempo){
							pair<int,int> aux;
							aux={right.front().first,tiempo+t};
							sol.push_back(aux);
							right.pop();
						}
					}
					tiempo+=t;
					lugar=0;
				}
				else if(left.size()!=0 and right.size()!=0 and right.front().second<=left.front().second){//los autos llegan antes por la derecha
					tiempo=right.front().second;
				}
				else if(left.size()!=0 and right.size()!=0){//los autos llegan antes por la izquierda
					tiempo=max(left.front().second,tiempo);
					tiempo+=t;
					lugar=0;
				}
				else if(right.size()==0){//no llegaran autos por la derecha
					tiempo=max(tiempo,left.front().second);
					tiempo+=t;
					lugar=0;
				}
				else if(left.size()==0){//no llegaran autos por la izquierda
					tiempo=right.front().second;
				}
			}
		}
		for (int i = 0; i < sol.size(); ++i)//se imprime resultado
		{
			for(int j=0;i<sol.size();j++){
				if(sol[j].first==i){
					cout<<sol[j].second<<endl;
					break;
				}
			}
		}
		if(k<c-1){//endl final
			cout<<endl;
		}
	}
	return 0;
}