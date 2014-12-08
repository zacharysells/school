#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <vector>

// data_t represents an edge of the graph
typedef std::pair< std::pair<int,int>, double> data_t;

//edge_it is an iterator for the edge map
typedef std::map< std::pair<int,int>, double>::const_iterator edge_it;

class Graph
{

    public:
    Graph( const int& nodes, const bool& directed );
    ~Graph();

    int V() const;
    int E() const;
    bool directed() const;
    void insert( const int& s, const int& t, const double& weight );
    void remove( const int& s, const int& t );
    bool edge( const int& s, const int& t);
    edge_it getEdge( const int& s, const int& t);
    void show() const;
    std::vector<data_t> sorted_edges();
    std::vector<int> topological_sort();
    int connected_components();
    bool containsCycle();
    std::vector<data_t> maxSubMST();
    void dfs(int v);
    void DFS_VISIT(int u);
    std::vector<int> Get_Adg_List(int u);
    std::vector<data_t> MST_Kruskal();
    std::vector<data_t> kruskal();
    std::set<int> dijkstra();

    int* color;
    std::vector<int> Dfs_List;

        private:
    int nNodes;
    int nEdges;
    bool isDirected;

    //this map contains the edges of the graph
    std::map< std::pair<int,int>, double > edge_map;

};

#endif /* GRAPH_H_ */
