#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
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
      cout << "(" << g.vCount << "," << g.eCount << ")";
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
