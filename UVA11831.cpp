#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> matrix;   
string s;

int stickers(int N,int M);

int main(){
	int N,M,S;
	while(cin>>N>>M>>S){
		if(N==0 and M==0 and S==0)break;
		matrix.resize(N);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				char x;
				cin>>x;
				matrix[i].push_back(x);
			}
		}
		for(int i=0;i<S;i++){
			char x;
			cin>>x;
			s.push_back(x);
		}
		int sticker=stickers(N,M);
		cout<<sticker<<endl;
		s.clear();
		matrix.clear();
	}
	return 0;
}

int stickers(int N, int M){
	int sticker=0,posx=-1,posy=-1,x;
	char dir[4]={'N','L','S','O'};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(matrix[i][j]=='N' or matrix[i][j]=='S' or matrix[i][j]=='L' or matrix[i][j]=='O'){
				switch(matrix[i][j]){
					case 'N':
						x=0;
					break;
					case 'L':
						x=1;
					break;
					case 'S':
						x=2;
					break;
					case 'O':
						x=3;
					break;
				}
				matrix[i][j]='.';
				posx=j;
				posy=i;
				break;
			}
		}
		if(posx!=-1)break;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='F'){
			//dependiendo de orientaición
			int nposx,nposy;
			if(dir[x]=='N'){
				nposx=posx;
				nposy=posy-1;
			}
			else if(dir[x]=='S'){
				nposx=posx;
				nposy=posy+1;
			}
			else if(dir[x]=='L'){
				nposx=posx+1;
				nposy=posy;
			}
			else if(dir[x]=='O'){
				nposx=posx-1;
				nposy=posy;
			}
			//vemos el caso
			if(nposx==-1 or nposx==M or nposy==-1 or nposy==N)continue;
			if(matrix[nposy][nposx]=='*'){
				matrix[nposy][nposx]='.';
				sticker++;
				posx=nposx;
				posy=nposy;
			}
			else if(matrix[nposy][nposx]=='.'){
				posx=nposx;
				posy=nposy;
			}
		}
		else if(s[i]=='D'){
			x=(x+1)%4;
		}
		else{
			x--;
			if(x<0)x+=4;
		}
		//cout<<posx<<" "<<posy<<dir[x]<<endl;
	}
	return sticker;
}
