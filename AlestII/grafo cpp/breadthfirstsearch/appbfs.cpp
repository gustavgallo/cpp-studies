#include <iostream>
#include "../graph.h"
#include "breadthfirstsearch.h"

using namespace std;

int main()
{
  Graph g("../tinyG.txt");
  BreadthFirstSearch bfs(g, "0");

  for (auto const &v : g.getVerts())
  {
    cout << v << ": ";
    if (bfs.hasPathTo(v))
    {
      for (auto const &w : bfs.pathTo(v))
        cout << w << " ";
    }
    cout << endl;
  }
}
