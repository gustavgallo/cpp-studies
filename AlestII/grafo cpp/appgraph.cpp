#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    //Graph g("tinyG.txt");
    Graph g("mediumG.txt");
    // g.addEdge("0", "1");
    // g.addEdge("0", "2");
    // g.addEdge("2", "1");

    for (auto const& v : g.getVerts()) {
      cout << v << ": ";
      for (auto const& w : g.getAdj(v))
        cout << w << " ";
      cout << endl;
	}

  cout << endl;
  cout << g.toDot();
}
