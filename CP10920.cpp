#include <bits/stdc++.h>

using namespace std;
int main(){
	double p, sz;
	int le,pos,Y,X,centro;
	cin>>sz>>p;
	while(sz!=0 and p!=0){
		centro=(sz+1)/2;
		for (le = 1; le < sz; le+=2)//definimos lado externo
		{
			if (p<=(pow(le,2)))
			{
				break;
			}
		}
		pos=(p-pow(le-2,2));//obtenemos la posicion inicial en el anillo en el que estamos
		if (pos<=le-1)//si la posicion esta en el primer cuarto
		{
			X=centro+le/2-pos;
			Y=centro+le/2;
		}
		else if (pos<=2*(le-1))//segundo cuarto
		{
			X=centro-le/2;
			Y=centro +le/2-(pos-(le-1));
		}
		else if (pos<=3*(le-1))//tercer cuarto
		{
			X=centro-le/2+(pos-2*(le-1));
			Y=centro-le/2;
		}
		else{//cuarto cuarto
			X=centro+le/2;
			Y=centro-le/2+(pos-3*(le-1));
		}
		cout<<"Line = "<<Y<<", column = "<<X<<"."<<endl;
		cin>>sz>>p;
	}
	return 0;
}