#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;//test cases
	while(N--){
		int A,B,C,lim;//datos
		int x=0,y=0,z=0;
		bool encontrado=false;
		cin>>A>>B>>C;
		lim=sqrt(C);//obtenemos limite maximo y minimo utilizando la tercera ecuacion
		for(int i=-lim;i<=lim;i++){//testeamos todas las posibilidades dentro del rango
			for(int j=-lim;j<=lim;j++){
				for(int k=-lim;k<=lim;k++){
					if(i+j+k==A and i*j*k==B and i*i+j*j+k*k==C and i!=j and j!=k and i!=k){//revisamos si cumple
						encontrado=true;
						x=i;
						y=j;
						z=k;
						break;
					}
				}
				if(encontrado)break;
			}
			if(encontrado)break;
		}
		if(encontrado)cout<<x<<" "<<y<<" "<<z<<endl;//se imprime resultado
		else cout<<"No solution."<<endl;//no se encontro resultado
	}
	return 0;
}