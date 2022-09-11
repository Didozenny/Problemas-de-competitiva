#include <bits/stdc++.h>

using namespace std;

int changeNum(int num){//funcion que transforma los numeros de 0 al 61 a valores validos para el ejercicio
		if(num==61)num=50;
		else if(num>40)num=(num-40)*3;
		else if(num>20)num=(num-20)*2;
		return num;
}

bool repetido(int num, int i){//funcion que identifica si se ha visto este valor antes con un i anterior
	if(i>20 and i<41 and num<=20)return true;
	else if(i>40 and i<61 and (num<=20 or (num>=22 and num<=40 and num%2==0)))return true;
	return false;
}

int main(){
	int s;
	cin>>s;
	while(s>0){//score
		int P=0,C=0;
		int comb[3];
		for(int i=0;i<=61;i++){//numero a testear
			int num=changeNum(i);
			if(repetido(num,i))continue;//ya se vio esta combinacion
			for(int j=i+1;j<=61;j++){//num no se repite
				int num2=changeNum(j);
				if(repetido(num2,j))continue;//se vio combinacion antes
				for(int k=j+1;k<=61;k++){
					int num3=changeNum(k);
					if(repetido(num3,k))continue;//se vio combinacion antes
					if(num+num2+num3==s){//se agrega una combinacion y como son 3 elementos distintos 6 permutaciones
						C++;
						P+=6;
					}
				}
			}
			for(int j=0;j<=61;j++){//num se repite una vez
				int num2=changeNum(j);
				if(repetido(num2,j))continue;//comb repetida
				if((num+num+num2)==s and num!=num2){//combinacion nueva con dos elementos iguales por lo que son 3 permutaciones nuevas
					C++;
					P+=3;
				}
			}
			if(num*3==s){//num se repite 3 veces, 1 comb nueva, 1 permutacion nueva
			C++;
			P++;
			}
		}
		//imprimimos resultado
		if(C==0)cout<<"THE SCORE OF "<<s<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
		else{
			cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<s<<" IS "<<C<<"."<<endl;
			cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<s<<" IS "<<P<<"."<<endl;
		}
		for(int j=0;j<70;j++)cout<<"*";
		cout<<endl;
		cin>>s;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}