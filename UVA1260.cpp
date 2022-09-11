#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;//test cases
	while(T--){
		int n,sum=0;
		cin>>n;
		vector<int> A;
		for(int i=0;i<n;i++){//lista A
			int x;
			cin>>x;
			A.push_back(x);
		}
		for(int i=1;i<n;i++){//verificamos dia a dia
			int sumx=0;
			for(int j=i-1;j>=0;j--){//revisamos todas las ventas de dias anteriores
				if(A[i]>=A[j]){
					sumx++;//contador de dias menores o iguales
				}
			}
			sum+=sumx;//contador total
		}
		cout<<sum<<endl;
	}
	return 0;
}