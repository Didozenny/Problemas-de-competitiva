/* 
Autor: Vicente Esteban Silva Vera
//se utilizo dikjstra obtenido en la pagina geek for geeks
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
1112 - Mice and Maze
Usuario: Didozenny ID: 1209597
Autoría propia
*/
#include <bits/stdc++.h>

using namespace std;

// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
  
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

vector<int> dist;
  
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
  
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
  
public:
    Graph(int V);  // Constructor
  
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
  
    // prints shortest path from s
    void shortestPath(int s);
};
  
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
  
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
  
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    dist.clear();
    dist.resize(V,INF);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
  
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main(){
	int cases;
	cin>>cases;
	for(int k=0;k<cases;k++){
        string str;
        getline(cin,str);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		int N,E,T,M;
        cin>>N>>E>>T>>M;
        Graph g(N);
        //cout<<"AGREGA ARISTAS"<<endl;
        for (int i = 0; i < M; ++i)
        {
            int a,b,w;
            cin>>a>>b>>w;
            g.addEdge(b-1,a-1,w);
        }
        //cout<<"SHORTEST PATH"<<endl;
        g.shortestPath(E-1);
        //cout<<"IMPRESION RESULTADOS"<<endl;
        //cout<<"FUENTE"<<E<<endl;
        int count=0;
        for (int i = 0; i < N; ++i)
        {
            if(dist[i]<=T)count++;
            //cout<<"distancia de "<<i<<": " <<dist[i]<<endl;
        }
        if(k!=0)cout<<endl;
        cout<<count<<endl;
	}
	return 0;
}