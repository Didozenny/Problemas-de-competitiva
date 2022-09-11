#include <bits/stdc++.h>

using namespace std;
int main(){
	long long int N,C,R,Q,Q2;
	cin>>N;
	bool hay= false;
	for (int i = 1; i <= N; ++i)
	{
		cin>>C>>R;
		cout<<"Case #"<<i<<":";
		if(C==R){
			cout<<" "<<'0';
		}
		else{
			for (int j = 1; j<sqrt(C-R); ++j)
			{//obtenemos los valores menores posibles
				if((C-R)%j==0){
					Q=(C-R)/j;
					if(R<j and j!=Q){
						cout<<" "<<j;
					}
				}
			}
			for (int j = sqrt(C-R); j > 0; --j)
			{
				if((C-R)%j==0){//obtenemos los valores mayores posibles
					Q=(C-R)/j;
					if(R<Q){
						cout<<" "<<Q;
					}
				}
			}

		}
		cout<<endl;
	}
}