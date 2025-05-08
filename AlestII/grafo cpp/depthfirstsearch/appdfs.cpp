#include <iostream>
#include "../graph.h"
#include "depthfirstsearch.h"

using namespace std;

int main()
{
  Graph g("../tinyG.txt");
  DepthFirstSearch dfs(g, "0");

  for (auto const &v : g.getVerts())
  {
    cout << v << ": ";
    if (dfs.hasPathTo(v))
    {
      for (auto const &w : dfs.pathTo(v))
        cout << w << " ";
    }
    cout << endl;
  }
}
