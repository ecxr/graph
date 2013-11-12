#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//template <class NodeValue>
class Graph
{
  typedef vector<vector<int>> EdgeList;
  typedef vector<vector<double>> WeightList;

  public:
    Graph(int n) {
      vCount = n;
      eCount = 0;

      adj.resize(n);
      weights.resize(n);
    }

    Graph(char* filename)
    {
      int u, v;
      double weight;

      ifstream file(filename);
      if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        // throw exception
        return;
      }

      file >> vCount;

      adj.resize(vCount);
      weights.resize(vCount);

      while  (file >> u >> v >> weight)
      {
        addEdge(u, v, weight);
      }
    }

    void addEdge(int u, int v, double weight) {
      // self-loops arent allowed
      if (u == v) return;

      int m = max(u,v);
      if (m > vCount) {
        adj.resize(m);
        weights.resize(m);
        vCount = m;
      }

      adj[u].push_back(v);
      adj[v].push_back(u);

      weights[u].push_back(weight);
      weights[v].push_back(weight);

      eCount++;
    }

    friend ostream& operator<<(ostream& out, Graph g)
    {
      out << "Graph has " << g.vCount << " vertices, and " << g.eCount << " edges" << endl;
      for (int i = 0; i < g.vCount; i++) {
        vector<int> edges = g.adj[i];
        out << i << ": ";
        for (int j = 0; j < edges.size(); j++) {
          out << edges[j] << " (" << g.weights[i][j] << "), ";
        }
        out << endl;
      }
      return out;
    }

  private:
    int vCount;
    int eCount;
    EdgeList adj;
    WeightList weights;
 //   vector<NodeValue> values;
};

#endif // _GRAPH_H
