#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num=1;
	double xo,yo,x,y;
	std::vector <string> resultado;
	cin>>num;
	while(num!=0){
		cin>>xo>>yo;
		for (int i = 0; i < num; ++i)
		{
			cin>>x>>y;
			if(x>xo and y>yo){
				resultado.push_back("NE");
			}
			else if(x<xo and y>yo){
				resultado.push_back("NO");
			}
			else if(x<xo and y<yo){
				resultado.push_back("SO");
			}
			else if(x>xo and y<yo){
				resultado.push_back("SE");
			}
			else resultado.push_back("divisa");
		}
		cin>>num;
	}
	for (int i = 0; i < resultado.size(); ++i)
	{
		cout<<resultado[i]<<endl;
	}
}