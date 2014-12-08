#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main()
{

    Graph G1( 6, true );
    G1.insert( 4, 1, 2.5 );
    G1.insert( 4, 2, 1.1 );
    G1.insert( 2, 3, 1.2 );
    G1.insert( 3, 6, 1.5 );
    G1.insert( 1, 0, 3.4 );
    //G1.insert( 4, 0, 1.5 );
    //G1.insert( 4, 2, 1.5 );
    G1.show();

           int n = G1.V();
        G1.dfs(0);
        for (int i = 0; i < n; ++i)
        {
        	std::cout<<G1.Dfs_List[i]<< " ";
        }
        std::cout << endl;

	
	
	vector<int> tmp = G1.topological_sort();

	for(unsigned i = 0; i < tmp.size(); i++)
		std::cout << tmp[i] << endl;

        //Add more testing here

    return 0;
}
