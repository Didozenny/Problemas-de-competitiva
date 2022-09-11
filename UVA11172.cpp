#include <iostream>

using namespace std;

int main(){
	int num;
	cin>>num;
	int n1[num], n2[num];
	for (int i = 0; i < num; ++i)
	{
		cin>>n1[i];
		cin>>n2[i];
	}
	for (int i = 0; i < num; ++i)
	{
		if(n1[i]<n2[i]){
			cout<<"<\n";
		}
		else if(n1[i]>n2[i]){
			cout<<">\n";
		}
		else cout<<"=\n";
	}

}