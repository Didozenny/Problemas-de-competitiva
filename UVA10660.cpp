#include <bits/stdc++.h>

using namespace std;

int pobl[5][5]={};

int solution[5]={0,1,2,3,4};

int value=INT_MAX;

void reset(){//reseteamos valores globales 
	for (int i = 0; i < 5; ++i)
	{
		solution[i]=i;
		for(int j=0;j<5;j++){
			pobl[i][j]=0;
		}
	}
	value=INT_MAX;
}

int dist(int x,int y,int n){//toma la distancia entre las coordenadas dadas y el numero correspondiente a la oficina
	int x2=n%5;//cordenadas oficina
	int y2=n/5;
	return (abs(y-y2)+abs(x-x2));
}

void combination(){
	for(int i=0;i<21;i++){//utilizamos 5 for para todas las posibles combinaciones relevantes
		for(int j=i+1;j<22;j++){
			for(int k=j+1;k<23;k++){
				for(int l=k+1;l<24;l++){
					for(int m=l+1;m<25;m++){
						//evaluamos
						int sum=0;
						for(int x=0;x<5;x++){
							for(int y=0;y<5;y++){
								if(pobl[y][x]==0)continue;
								int dis=dist(x,y,i);
								dis=min(dis,dist(x,y,j));
								dis=min(dis,dist(x,y,k));
								dis=min(dis,dist(x,y,l));
								dis=min(dis,dist(x,y,m));
								sum+=dis*pobl[y][x];//sumamos la menor distancia entre el cuadro y la oficina mas cercana
							}
						}
						if(sum<value){//verificamos si la nueva solucion es mejor que la mejor anterior
							value=sum;//reemplazamos con nuevos datos
							solution[0]=i;
							solution[1]=j;
							solution[2]=k;
							solution[3]=l;
							solution[4]=m;
						}
					}
				}
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){//test cases
		reset();
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{//armamos la matriz
			int row,column,ppl;
			cin>>row>>column>>ppl;
			pobl[row][column]=ppl;
		}
		combination();
		cout<<solution[0]<<" "<<solution[1]<<" "<<solution[2]<<" "<<solution[3]<<" "<<solution[4]<<endl;//imprimimos resultado
	}
	return 0;
}