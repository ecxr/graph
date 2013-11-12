#include <iostream>
#include <cassert>

#include "graph.h"
#include "ShortestPath.h"
#include "util.h"


void test_file_constructor()
{
  cout << "testing reading graph from a file" << endl;
  Graph g("newgraph.txt");
  cout << g << endl;
}

void test_radomized_constructor(int n, double density, double weightLow, double weightHigh)
{
  cout << "testing randomized constructor with " << n << " vertices with density "
       << density << " and weight between " << weightLow << " and " << weightHigh << endl;
  Graph g(n, density, weightLow, weightHigh);
  cout << g << endl;
}

void test_add_edge_and_getters()
{
  cout << "Testing addEdge and getters" << endl;
  Graph g(10);

  for (int i = 0; i < 10; i++) {
    g.addEdge(i, (i + 3) % 10, (double)i);
    g.addEdge(i, (i + 2) % 10, (double)i + .5);
    assert(g.edges() == 2 * (i+1));
    assert(g.vertices() == 10);
    
  }
  cout << g << endl;
}

void test_set_edge_weght()
{
  cout << "Testing setEdgeWeight" << endl;
  Graph g(10);

  for (int i = 0; i < 10; i++) {
    g.addEdge(i, (i + 3) % 10, (double)i);
    g.addEdge(i, (i + 2) % 10, (double)i + .5);
  }

  assert(g.getEdgeWeight(0, 3) == 0.0);
  assert(g.getEdgeWeight(3, 0) == 0.0);
  assert(g.getEdgeWeight(9, 6) == 6.0);
  assert(g.getEdgeWeight(6, 9) == 6.0);

  g.setEdgeWeight(9, 6, 3.0);
  assert(g.getEdgeWeight(9, 6) == 3.0);
  assert(g.getEdgeWeight(6, 9) == 3.0);

  cout << g << endl;
}


void test_del_edge() {
  cout << "Testing delEdge" << endl;
  Graph g(10);
  for (int i = 0; i < 10; i++) {
    g.addEdge(i, (i + 3) % 10, (double)i);
  }

  assert(g.getEdgeWeight(2,5) == 2.0);
  g.delEdge(2, 5);
  assert(g.getEdgeWeight(2,5) != 2.0);
  
  cout << g << endl;
}

// Runs a monte carlo simulation, for nTests, creating a random graph with the given nodes and density, each
// edge with a cost between costLow and costHigh
void monte_carlo(int nTests, int nodes, double density, double costLow,
    double costHigh)
{
  double total_edges = 0.0;
  for (int i = 0; i < nTests; ++i)
  {
    Graph g(nodes, density, costLow, costHigh);
    ShortestPath sp(&g, 0);

    total_edges += g.edges();
  }

  cout << "Average number of edges for a graph with " << nodes << " nodes and a density of " <<
    density << " is " << static_cast<double>(total_edges / nTests) << endl;
}

void test_monte_carlo()
{
  cout    << "10 tests of 50 nodes with density of 20% with weight between 1.0 and 10.0"
    << endl;
  monte_carlo(10, 50, 0.20, 1.0, 10.0);

  cout << endl;

  cout    << "10 tests of 50 nodes with density of 40% with weight between 1.0 and 10.0"
    << endl;
  monte_carlo(10, 50, 0.40, 1.0, 10.0);
}

int main(int argc, char* argv[])
{
  srand(time(0));
  test_file_constructor();
  test_radomized_constructor(10, 0.20, 1.0, 10.0);
  test_add_edge_and_getters();
  test_del_edge();
  test_set_edge_weght();
  test_monte_carlo();

  return 0;
}

