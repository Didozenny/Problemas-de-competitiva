/* 
Autor: Vicente Esteban Silva Vera
//se utilizo Disjoin set obtenido en geek for geeks para este ejercicio
https://www.geeksforgeeks.org/disjoint-set-data-structures/
793 Network connections
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

class DisjSet {
	int *rank, *parent, n;

public:
	// Constructor to create and
	// initialize sets of n items
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Creates n single item sets
	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// Finds set of given item x
	int find(int x)
	{
		// Finds the representative of the set
		// that x is an element of
		if (parent[x] != x) {

			// if x is not the parent of itself
			// Then x is not the representative of
			// his set,
			parent[x] = find(parent[x]);

			// so we recursively call Find on its parent
			// and move i's node directly under the
			// representative of this set
		}

		return parent[x];
	}

	// Do union of two sets represented
	// by x and y.
	void Union(int x, int y)
	{
		// Find current sets of x and y
		int xset = find(x);
		int yset = find(y);

		// If they are already in same set
		if (xset == yset)
			return;

		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

int main(){
	int cases;
	cin>>cases;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string str;
	getline(cin,str);
	while(cases--){
		int n,correct=0,incorrect=0;
		cin>>n;
		DisjSet	obj(n);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while(getline(cin,str) and str!=""){
			istringstream iss(str);
			int a,b;
			char c;
			iss >> c;
			iss >> b;
			iss >> a;
			a=a-1;
			b=b-1;
			if(c=='c')obj.Union(a,b);
			else if(obj.find(a)==obj.find(b))correct++;
			else incorrect++;
		}
		cout<<correct<<","<<incorrect<<endl;
		if(cases!=0)cout<<endl;

	}
}