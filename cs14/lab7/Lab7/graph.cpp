#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include "graph.h"
#include <set>

using namespace std;

template<class T>
struct less_second
: std::binary_function<T,T,bool>
{
   inline bool operator()(const T& lhs, const T& rhs)
   {
      return lhs.second < rhs.second;
   }
};


Graph::Graph( const int& nodes, const bool& directed )
{
        nNodes = nodes;
    nEdges = 0;
    isDirected = directed;
}

Graph::~Graph()
{}

edge_it Graph::getEdge( const int& s, const int&t )
{
        std::pair<int,int> p( s, t );
    edge_it mit = edge_map.find( p );

    return mit;
}

// Check if edge exists between end nodes
bool Graph::edge( const int& s, const int& t)
{
    return getEdge( s, t ) != edge_map.end();
}

// Add an edge: map node pair with weight
void Graph::insert( const int& s, const int& t, const double& weight )
{
        std::pair<int,int> p1( s, t );
    std::pair<int,int> p2( t, s );
    edge_map[ p1 ] = weight;

    if ( !isDirected )
    {
            edge_map[ p2 ] = weight;
    }

    nEdges++;
}

// Remove selected edge - remove both directions
// if graph is not directed
void Graph::remove( const int& s, const int& t )
{
        std::pair<int,int> p1( s, t );
    std::map< std::pair<int,int>, double>::iterator mit = edge_map.find( p1 );
    edge_map.erase( mit );

    if ( !isDirected )
    {
        std::pair<int,int> p2( t, s );
        mit = edge_map.find( p2 );
        edge_map.erase( mit );
    }

    nEdges--;
}

// Print the network topology
void Graph::show() const
{
        edge_it mit = edge_map.begin();

    for ( ; mit != edge_map.end(); ++ mit )
    {
            std::pair<int,int> p = (*mit).first;
        std::cout << p.first  << " " <<
                   p.second << " " <<
                   (*mit).second << std::endl;
    }
}

// Return true if graph is directed; false otherwose
bool Graph::directed() const
{
    return isDirected;
}

// Return number of network nodes
int Graph::V() const
{
    return nNodes;
}

// Return number of edges
int Graph::E() const
{
        return nEdges;
}


//This function returns the Minimum Spanning Tree (MST) of this graph (Kruskal)
std::vector<data_t> Graph::MST_Kruskal()
{
    int i, number;
    int cicles[this->V()];
    std::vector<data_t> mst;
    mst.clear();
    std::vector<data_t> edges = sorted_edges();

    for( i=0; i < this->V(); i++) cicles[ i ] = i;

    while( (int) mst.size() < ( this->V() - 1) && edges.size() )
    {
        data_t dt = edges[ 0 ];
        std::pair<int,int> p = dt.first;
        int vi = p.first;
        int vj = p.second;

        if( cicles[ vi ] != cicles[vj] )
        {
            number = cicles[ vj ];
            for( i=0; i < this->V(); i++ )
            {
               if( cicles[ i ] == number )
                  {
                     cicles[ i ] = cicles[ vi ];
                  }
            }

            mst.push_back( dt );
        }
        edges.erase( edges.begin(), edges.begin() + 1 );
    }

    return mst;
}


/*
 * This function uses std::sort to sort the weighted edges of the graph
 * into nondecreasing order by weight
 */

bool is_in(vector<int> & v, int e)
{
        for(unsigned i = 0; i < v.size(); i++)
        {
                if(v.at(i) == e) return true;
        }
        return false;

}


std::vector<data_t> Graph::sorted_edges()
{
        std::vector< data_t > vec(edge_map.begin(), edge_map.end());

        std::sort(vec.begin(), vec.end(), less_second<data_t>());

        return vec;
}

        // Depth first search of this graph
void Graph::dfs(int v) {
	int nComponents = 0;
	std::cout << "\n In DFS \n";
	color = new int[V()];

	std::stack<int> vertices;
	for (int i = V() - 1; i >= 0; i--){
		if (i != v) vertices.push(i);
	}
	vertices.push(v);

	for (int u = 0; u < V(); u++)
	{
		color[u] = 0;
	}
	while (!vertices.empty())
	{
		int current_vertex = vertices.top();
		vertices.pop();
		if (color[current_vertex] == 0)
			DFS_VISIT(current_vertex);
	}

}
void Graph::DFS_VISIT(int u){
	//find the adgencency list of u
	std::vector<int> Adj;
	Adj = this->Get_Adg_List(u);
	color[u] = 1;
	for (int i = 0; i < Adj.size(); i++)
		if (color[Adj[i]] == 0)
			DFS_VISIT(Adj[i]);
	color[u] = 2;
	//std::cout << " " << u;
	Dfs_List.push_back(u);
}

std::vector<int> Graph::Get_Adg_List(int u) {

	std::vector<int> Adg;
	std::vector<data_t> edges = sorted_edges();
	int i = 0;
	while( i < edges.size() )
	{
	    data_t dt = edges[ i ];
	    std::pair<int,int> p = dt.first;
	    if (u == p.first) Adg.push_back(p.second);
	    i++;
	}
	return Adg;
}

int d[V()];
int pi[V()];
int i = 0;
std::stack<int> V_S;
	for (int i = V() - 1; i >= 0; i--){
		if (i != v) V_S.push(i);
	}
std::vector<data_t> edges = sorted_edges();
	
void initialize_single_source(int s)
{
	for(unsigned i = 0; i < V_S.size(); i++)
	{
		d[v] = 999999;
		pi[v] = -1;
	}
	d[s] = 0;
}

void relax(data_t &tmp)
{
	if(d[tmp.first.second] > d[tmp.first.first] + tmp.second)
	{
		d[tmp.first.second] = d[tmp.first.first] + tmp.second;
		pi[tmp.first.second] = tmp.first.first;
	}
}

std::set<int> Graph::dijkstra()
{
	std::set<int> S;
	initialize_single_source(s);
	while(!V_S.empty())
	{
		u = edges.at(i).first.first;
		i++;
		S.push(u);
		for(unsigned i = 0; i < edges.size(); i++)
		{
			if(edges[i].first.first == u) relax(edges[i]);
		}
	}		
	return S;
}

vector<data_t> Graph::kruskal()
{
	vector<data_t> A;
	vector<int> nodes;
	vector<data_t> edges = sorted_edges();
	//for(unsigned i=0; i < edges.size(); i++) nodes.push_back(i.first.first);
			
	//sort E in increasing order by weight w
	for (unsigned i = 0; i < edges.size(); i++);
	{
		//if (find(edges[i].first.first) != find(edges[i.first.second])) 
		{ // u and v in different trees
			//add (u, v) to A
			//data_t tmp;
			//unionSets(u, v);
		}
	}	
	//return A
	
}



    /*
     * This function returns a topological ordering of a Directed Graph
     * topological sort works only on directed acyclic graphs (DAG)
     */
    std::vector<int> Graph::topological_sort()
    {
		vector<int> topSort;
		for(int i = Dfs_List.size()-2;i >= 0; i--)
		{
			topSort.push_back(Dfs_List[i]);
		}
		return topSort;
    }

    /*
     * This function returns the number of strongly connected components in this graph
     */

    int Graph::connected_components()
    {

    }


    /*
     * This function checks if the current graph contains a cycle
     */

    bool Graph::containsCycle()
    {

    }


    /*
     * This function returns the maximum MST of all subgraphs of size n-1
     * where n is the number of vertices in this graph
     */

    std::vector<data_t> Graph::maxSubMST()
    {

    }
