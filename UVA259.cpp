/* 
Autor: Vicente Esteban Silva Vera
Se utilizo codigo hungarian entregado por el ayudante
259 - Software Allocation
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>
using namespace std;

#define tipo double
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
const tipo EPS = 1e-9;
const tipo INF = 1e14;
#define N 502 





//Dado un grafo bipartito completo con costos no negativos, encuentra el matching perfecto de minimo costo.
tipo cost[N][N], lx[N], ly[N], slack[N]; //llenar: cost=matriz de adyacencia
int n, max_match, xy[N], yx[N], slackx[N],prev2[N];//n=cantidad de nodos
bool S[N], T[N]; //sets S and T in algorithm
void add_to_tree(int x, int prevx) {
	S[x] = true, prev2[x] = prevx; 
	forn(y, n) if (lx[x] + ly[y] - cost[x][y] < slack[y] - EPS)
		slack[y] = lx[x] + ly[y] - cost[x][y], slackx[y] = x;
}
void update_labels(){
	tipo delta = INF; 
	forn (y, n) if (!T[y]) delta = min(delta, slack[y]);
	forn (x, n) if (S[x]) lx[x] -= delta;
	forn (y, n) if (T[y]) ly[y] += delta; else slack[y] -= delta;
}
void init_labels(){
	zero(lx), zero(ly);
	forn (x,n) forn(y,n) lx[x] = max(lx[x], cost[x][y]);
}
void augment() {
	if (max_match == n) return; 
	int x, y, root, q[N], wr = 0, rd = 0; 
	memset(S, false, sizeof(S)), memset(T, false, sizeof(T)); 
	memset(prev2, -1, sizeof(prev2)); 
	forn (x, n) if (xy[x] == -1){
		q[wr++] = root = x, prev2[x] = -2;
		S[x] = true; break; }
	forn (y, n) slack[y] = lx[root] + ly[y] - cost[root][y], slackx[y] = root;
	while (true){
		while (rd < wr){
			x = q[rd++];
			for (y = 0; y < n; y++) if (cost[x][y] == lx[x] + ly[y] && !T[y]){
				if (yx[y] == -1) break; T[y] = true; 
				q[wr++] = yx[y], add_to_tree(yx[y], x); }
			if (y < n) break; }
		if (y < n) break; 
		update_labels(), wr = rd = 0; 
		for (y = 0; y < n; y++) if (!T[y] && slack[y] == 0){
			if (yx[y] == -1){x = slackx[y]; break;}
			else{
				T[y] = true; 
				if (!S[yx[y]]) q[wr++] = yx[y], add_to_tree(yx[y], slackx[y]);
			}}
		if (y < n) break; }
	if (y < n){
		max_match++; 
		for (int cx = x, cy = y, ty; cx != -2; cx = prev2[cx], cy = ty)
			ty = xy[cx], yx[cy] = cx, xy[cx] = cy;
		augment(); }
}
tipo hungarian(){
	tipo ret = 0; max_match = 0, memset(xy, -1, sizeof(xy)); 
	memset(yx, -1, sizeof(yx)), init_labels(), augment(); //steps 1-3
	forn (x,n) ret += cost[x][xy[x]]; return ret;
}

int main(){
	n = 10;//maximo de 10 computadoras
	string s;
	while(getline(cin,s)){
		for (int i = 0; i < 10; ++i)
		{
			for(int j=0;j<10;j++){
				cost[i][j]=0;
			}
		}

		int sumval=0;//cantidad total de programas
		char letraIndice[10];//relacion indice con programas
		for(int i=0;i<10;i++)letraIndice[i]='_';//inicializacion

		//procesamos la primera linea para continuar con las siguientes
		int repeticiones=((int)s[1]-48);//cuantas veces se repite
		sumval+=repeticiones;//cantidad total de programas
		for(int j=sumval-repeticiones;j<sumval;j++){
			if(sumval<10)letraIndice[j]=s[0];//asignamos letra a indice
			for(int i=3;i<s.size()-1;i++){//relacionamos computadores con programas armando matriz
				cost[(int)s[i]-48][j]=1;
			}
		}
		while(getline(cin,s)and s!=""){//repetimos con las siguientes lineas
			int repeticiones=((int)s[1]-48);
			sumval+=repeticiones;
			for(int j=sumval-repeticiones;j<sumval;j++){
				letraIndice[j]=s[0];
				for(int i=3;i<s.size()-1;i++){
					cost[(int)s[i]-48][j]=1;
				}
			}
		}
		if(sumval!=hungarian()){//cantidad de programas coincide con el resultado
			cout<<"!"<<endl;
			continue;
		}

		/*for(int i = 0; i < n; i++){
			for(int j = 0;j < n; j++){
				cout << cost[i][j] << " ";
			}
			cout << endl;
		}*/

		for(int i = 0; i < n; i++)cout << letraIndice[xy[i]];//imprimimos resultado
		cout << endl;
	}
	return 0;
}






