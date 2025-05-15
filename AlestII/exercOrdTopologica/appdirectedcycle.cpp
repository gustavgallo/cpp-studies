#include <iostream>
#include "headers/digraph.h"
#include "headers/directedcycle.h"

using namespace std;

int main()
{
  Digraph g("es.txt");
  DirectedCycle dcycle(g);

  cout << g.toDot() << endl;

  cout << "Tem ciclo? " << dcycle.containsCycle() << endl;
}
