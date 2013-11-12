/*
 * ShortestPath ADT: Implements Djikstra's algorithm to find the shortest path
 * between two nodes in a graph
 *
 * Author: Sky King (skyking@gmail.com)
 *
 *
 */

#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include <vector>
#include "graph.h"

using namespace std;

typedef struct path {
  double weight;
  vector<int> nodes;
} path;

class ShortestPath
{
  public:
  ShortestPath() {
    Graph g(10);
    start = 0;
    paths = dijkstra();
  }

  ShortestPath(Graph* g, int start) {
    graph = g;
    start = start;
    paths = dijkstra();
  }

  // find shortest path between u-w and returns the sequence of vertices
  // representing shorest path u-v1-v2-…-vn-w.
  vector<int> pathTo(int end) {
    return paths[end].nodes;
  }

  double weightTo(int end) {
    return paths[end].weight;
  }

  // list of vertices in G(V,E)
  vector<int> vertices(Graph g, vector<int> v);

  private:
    Graph* graph;
    int start;
    vector<path> paths;
    vector<path> dijkstra() {
      vector<path> toreturn;
      for (int i = 0; i < graph->vertices(); i++) {
        path foo;
        vector<int> bar;
        bar.push_back(i+1);
        foo.weight = (double)i;
        foo.nodes = bar;
        toreturn.push_back(foo);
      }

      return toreturn;
    }

};

#endif // _SHORTESTPATH_H
