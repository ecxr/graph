#include <iostream>
#include <cassert>

#include "graph.h"
#include "util.h"


void test_file_constructor()
{
  cout << "testing reading graph from a file" << endl;
  Graph g("newgraph.txt");
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

int main(int argc, char* argv[])
{
  test_file_constructor();
  test_add_edge_and_getters();
  test_del_edge();
  test_set_edge_weght();

  return 0;
}

