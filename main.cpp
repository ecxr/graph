#include <iostream>

#include "graph.h"
#include "util.h"

int main(int argc, char* argv[])
{
  cout << "initializing graph" << endl;
  Graph g(10);

  cout << "adding edges" << endl;
  for (int i = 0; i < 10; i++) {
    g.addEdge(i, (i + 3) % 10, (double)i);
  }
  cout << g << endl;
/*
  cout << "reading graph from a file";
  Graph g2("testgraph.txt");
  cout << g2 << endl;

  cout << "main" << endl;
  return 0;
  */
}

