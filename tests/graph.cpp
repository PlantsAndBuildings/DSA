#define BOOST_TEST_MODULE graph
#include "../src/data_structures/graph/undirected_graph.hpp"
#include <boost/test/unit_test.hpp>

struct GraphTestFixture {
  GraphTestFixture() : undirectedIntGraph(graph::UndirectedGraph<int>()) {}

  ~GraphTestFixture() {}

  graph::UndirectedGraph<int> undirectedIntGraph;
};

/**
 * Trivial Case: Add vertex
 */
BOOST_FIXTURE_TEST_CASE(undirected_int_graph_add_vertex, GraphTestFixture) {
  undirectedIntGraph.addVertex(2);
  undirectedIntGraph.addEdge(3, 4);
}
