#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool isS=true,isQ=true,isPQ=true;
		for(int i=0;i<n;i++){
			int function, value;
			cin>>function>>value;
			if(function==1){
				s.push(value);
				q.push(value);
				pq.push(value);
			}
			else{
				if(s.size()!=0){
					if(value!=s.top()){
						isS=false;
					}
					s.pop();	
				}
				else isS=false;
				if(q.size()!=0){
					if(value!=q.front()){
						isQ=false;
					}
					q.pop();
				}
				else isQ=false;
				if(pq.size()!=0){
					if(value!=pq.top()){
						isPQ=false;
					}
					pq.pop();
				}
				else isPQ=false;
			}
		}
		if(isS and !isPQ and !isQ){
			cout<<"stack"<<endl;
		}
		else if(!isS and !isPQ and isQ){
			cout<<"queue"<<endl;
		}
		else if(!isS and isPQ and !isQ){
			cout<<"priority queue"<<endl;
		}
		else if(isS or isPQ or isQ){
			cout<<"not sure"<<endl;
		}
		else{
			cout<<"impossible"<<endl;
		}
	}
	return 0;
}