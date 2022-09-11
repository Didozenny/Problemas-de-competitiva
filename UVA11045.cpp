/* 
Autor: Vicente Esteban Silva Vera
Se utilizo codigo hungarian entregado por el ayudante
11045 - My T-shirt suits me
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
	int cases;
	cin>>cases;
	map <string,int> talla;
	talla["XS"]=0;//relacionamos cada talla con un valor
	talla["S"]=1;
	talla["M"]=2;
	talla["L"]=3;
	talla["XL"]=4;
	talla["XXL"]=5;
	for (int cont = 0; cont < cases; ++cont){//revisamos los casos
		int Nn,Mm;
		cin>>Nn>>Mm;
		n=Nn;
		int amount=Nn/6;//cantidad de elementos por talla
		cin.ignore();//limpiamos buffer
		for (int i = 0; i < Mm; ++i){
			string s,s1,s2;
			getline(cin,s);
			istringstream(s)>>s1>>s2;//obtenemos las dos tallas
			//relacionamos el elemento con todos los nodos que representan las tallas. Orden tallas: XS XS XS...XSn S S S...Sn......XXLn
			for(int j=talla[s1]*amount;j<talla[s1]*amount+amount;j++){
				cost[i][j]=1;
			}
			for(int j=talla[s2]*amount;j<talla[s2]*amount+amount;j++){
				cost[i][j]=1;
			}
		}
		if(hungarian()==Mm)cout<<"YES"<<endl;//si el flujo maximo coincide con la cantidad de jugadores acepta
		else cout<<"NO"<<endl;
		for(int i = 0; i < n; i++){//reiniciamos tabla para siguiente caso
			for(int j = 0;j < n; j++){
				cost[i][j]=0;
			}
		}
	}

	return 0;
}