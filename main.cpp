#include <iostream>

#include "graph.h"
#include "util.h"

void test_graph()
{
  cout << "testing reading graph from a file" << endl;
  Graph g("/home/ubuntu/cpp/graph2/newgraph.txt");
  cout << g << endl;
}

void test_edges()
{
  cout << "Testing addEdge" << endl;
  Graph g(10);

  for (int i = 0; i < 10; i++) {
    g.addEdge(i, (i + 3) % 10, (double)i);
  }
  cout << g << endl;
}

int main(int argc, char* argv[])
{
  test_graph();
  test_edges();

  return 0;
}

