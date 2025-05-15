#include "headers/graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

Graph::Graph() {
}

Graph::Graph(string filename) {
	ifstream file;
	file.open(filename);
	string line, v, w;
	if(file.is_open()) {
		while(getline(file, line)) {
			stringstream ss(line);
			getline(ss, v, '/');
			while(getline(ss, w, '/')){
				
  	    		addEdge(v, w);}
    	}
    	file.close();
	}
}

vector<string> Graph::getAdj(string v) {
	return graph[v];
}

vector<string> Graph::getVerts() {
	vector<string> keys;
	for(auto const& element : graph)
		keys.push_back(element.first);
	return keys;
}

void Graph::addEdge(string v, string w) {
	addToList(v, w);
	
}

string Graph::toDot() {
    // Usa um conjunto de arestas para evitar duplicatas
	set<string> edges;
	const string NEWLINE = "\n";
	string sb;
    sb = "graph {"+NEWLINE;
    sb += "rankdir = LR;"+NEWLINE;
    sb += "node [shape = circle];"+NEWLINE;
    for(auto const& v: getVerts()) {
      for (auto const& w: getAdj(v)) {
        string edge = v < w ? v + w : w + v;
        if(edges.find(edge) == edges.end()) {
          sb += v + " -- " + w + NEWLINE;
          edges.insert(edge);
        }
      }
    }
    sb += "}" + NEWLINE;
    return sb;
}

void Graph::addToList(string v, string w) {
	vector<string>& list = graph[v];
	list.push_back(w);
}
