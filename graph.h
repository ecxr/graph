#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "util.h"

using namespace std;

//template <class NodeValue>
class Graph
{
  typedef vector<vector<int>> EdgeList;
  typedef vector<vector<double>> WeightList;

  public:
    // Create an empty Graph on n vertices
    Graph(int n) {
      vCount = n;
      eCount = 0;

      adj.resize(n);
      weights.resize(n);
    }

    // Create a randomized graph with the given properties
    Graph(int size, double density, double low, double high)
    {
      vCount = size;
      eCount = 0;
      adj.resize(vCount);
      weights.resize(vCount);

      for (int i = 0; i < vCount; i++)
      {
        for (int j = 0; j < i; j++)
        {
          if (prob() < density)
          {
            double weight = low + (prob() * (high - low));
            addEdge(i, j, weight);
          }
        }
      }
    }

    // Read graph from a file
    Graph(const char* filename)
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

    double getEdgeWeight(int u,int v) {
      for (unsigned int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
          return weights[u][i];
        }
      }
      return INFINITY;
    }

    void setEdgeWeight(int u, int v, double w) {
      int found = 0;

      for (unsigned int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
          weights[u][i] = w;
          found++;
          break;
        }
      }

      for (unsigned int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
          weights[v][i] = w;
          found++;
          break;
        }
      }

      if (found == 0) addEdge(u, v, w);
      if (found == 1) cout << "HISSY FIT, SOMETHING'S WRONG IN SETEDGEWEIGHTTOWN";
    }

    void delEdge(int u,int v) {
      int found = 0;

      for (unsigned int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
          adj[u].erase(adj[u].begin() + i);
          weights[u].erase(weights[u].begin() + i);
          found++;
          break;
        }
      }
      for (unsigned int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
          adj[v].erase(adj[v].begin() + i);
          weights[v].erase(weights[v].begin() + i);
          found++;
          break;
        }
      }
      if (found == 2) eCount--;
      if (found == 1) cout << "HISSY FIT, SOMETHING'S WRONG IN DELEDGETOWN";
    }
    
    int edges() { return eCount; }
    int vertices() { return vCount; }

    friend ostream& operator<<(ostream& out, Graph g)
    {
      out << "Graph has " << g.vCount << " vertices, and " << g.eCount << " edges" << endl;
      for (int i = 0; i < g.vCount; i++) {
        vector<int> edges = g.adj[i];
        out << i << ": ";
        for (unsigned int j = 0; j < edges.size(); j++) {
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
