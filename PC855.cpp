#include <bits/stdc++.h>

using namespace std;
int main(){
	int T,S,A,F;
	int Av[50000],St[50000];
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>S>>A>>F;
		for (int i = 0; i < F; ++i)//introduces coordenadas de los amigos
		{
			int x,y;
			cin>>x>>y;
			St[i]=x;
			Av[i]=y;
		}
		sort(St,St+F);//Hacemos sort para luego obtener la mediana
		sort(Av,Av+F);
		if(F%2==0){//si es par
			cout<<"(Street: "<<St[F/2-1]<<", Avenue: "<<Av[F/2-1]<<")"<<endl;
		}
		else{//si es impar
			cout<<"(Street: "<<St[(F)/2]<<", Avenue: "<<Av[F/2]<<")"<<endl;
		}
	}
	return 0;
}