#include <map>
#include <string>
#include <vector>
#include <set>

#include "graph.h"

#ifndef DIGRAPH_H
#define DIGRAPH_H
using namespace std;

class Digraph : public Graph {
 public:
  Digraph() : Graph() {}
  Digraph(std::string filename);
  void addEdge(std::string v, std::string w);
  std::string toDot();
  set<string> vertices; 
  
};

#endif