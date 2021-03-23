#define BOOST_TEST_MODULE graph
#include "../src/data_structures/graph/undirected_graph.hpp"
#include "../src/algorithms/graph/dfs/dfs.hpp"
#include "../src/data_structures/graph/directed_graph.hpp"
#include <boost/test/unit_test.hpp>

struct GraphTestFixture {
  GraphTestFixture() : undirectedIntGraph(graph::UndirectedGraph<int>()), directedIntGraph(graph::DirectedGraph<int>()) {}

  ~GraphTestFixture() {}

  graph::UndirectedGraph<int> undirectedIntGraph;
  graph::DirectedGraph<int> directedIntGraph;
};

/**
 * Trivial Case: Add vertex and edge to undirected graph
 */
BOOST_FIXTURE_TEST_CASE(undirected_int_graph_add_vertex, GraphTestFixture) {
  undirectedIntGraph.addVertex(2);
  undirectedIntGraph.addVertex(3);
  undirectedIntGraph.addEdge(2, 3);
}

/**
 * Trivial Case: Add vertex and edge to directed graph
 */
BOOST_FIXTURE_TEST_CASE(directed_int_graph_add_vertex, GraphTestFixture) {
  directedIntGraph.addVertex(2);
  directedIntGraph.addVertex(3);
  directedIntGraph.addEdge(2, 3);
}

/**
 * Trivial Case: Perform DFS on a simple graph (two vertices, one edge)
 */
BOOST_FIXTURE_TEST_CASE(undirected_graph_dfs_test, GraphTestFixture) {
  undirectedIntGraph.addVertex(2);
  undirectedIntGraph.addVertex(3);
  undirectedIntGraph.addEdge(2, 3);

  graph::DepthFirstTraverser<int> depthFirstTraverser(undirectedIntGraph);

  depthFirstTraverser.traverse();
}