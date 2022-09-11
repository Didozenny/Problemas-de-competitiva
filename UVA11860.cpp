#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int k=0;k<n;k++){
		vector<string> words;
		unordered_map<string,int> u_m;
		unordered_set<string> u_s;
		string line;
		string aux;
		while(getline(cin,line) and line!="END"){
			line.insert(line.begin(),' ');
			for(int i=0;i< line.length();i++){
				if(!isalpha(line[i])){
					if(line[i]!=' '){
						line[i]=' ';
					}
				}
				if(i==line.length()-1 and line[i]==' ')line.erase(line.begin()+i);
			}
			int check=0;
			for(char c : line){
				if(isspace(c) and !check){
					aux.push_back(c);
					check=1;
				}
				else if(isalpha(c)){
					aux.push_back(c);
					check=0;
				}
			}
			if(aux[0] == ' ') aux.erase(aux.begin());
		}
		line.clear();
		istringstream iss(aux);
		while(iss>>line){
			words.push_back(line);
			u_s.insert(line);
		}
		int e=-1,s=0,q=words.size()-1,p=0,cant=0;
		while( e!=words.size()-1){
			e++;
			while(cant!=u_s.size() and e!=words.size()-1){
				u_m[words[e]]++;
				if(u_m[words[e]]==1){
					cant++;
				}
				if(cant!=u_s.size())e++;
				if(e==words.size()-1){
					u_m[words[e]]++;
					if(u_m[words[e]]==1){
					cant++;
					}
				}
			}
			if((e-s)<(q-p) and cant==u_s.size()){
				q=e;
				p=s;
			}
			while(u_m[words[s]]>1){
				u_m[words[s]]--;
				s++;
			}
			if((e-s)<(q-p) and cant==u_s.size()){
				q=e;
				p=s;
			}
			u_m[words[s]]--;
			s++;
			cant--;
		}
		cout<<"Document "<<k+1<<": "<<p+1<<" "<<q+1<<endl;
	}
	return 0;
}