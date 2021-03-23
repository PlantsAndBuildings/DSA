#define BOOST_TEST_MODULE graph
#include "../src/algorithms/graph/dfs/dfs.hpp"
#include "../src/algorithms/graph/kosaraju/scc_finder_kosaraju.hpp"
#include "../src/algorithms/graph/topological_sort/topological_sort.hpp"
#include "../src/data_structures/graph/directed_graph.hpp"
#include "../src/data_structures/graph/undirected_graph.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <boost/test/unit_test.hpp>

struct GraphTestFixture {
  GraphTestFixture()
      : undirectedIntGraph(graph::UndirectedGraph<int>()),
        directedIntGraph(graph::DirectedGraph<int>()) {}

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

/**
 * Trivial case: toposort on simple graph
 */
BOOST_FIXTURE_TEST_CASE(simple_graph_toposort_test, GraphTestFixture) {
  directedIntGraph.addVertex(2);
  directedIntGraph.addVertex(3);
  directedIntGraph.addEdge(2, 3);

  graph::TopologicalSorter<int> topoSorter(directedIntGraph);

  std::vector<int> topoSort = topoSorter.sort();

  LOG_INFO << logging::str(topoSort);
}

/**
 * Kosaraju's algorithm for finding strongly connected components on a simple
 * graph
 */
BOOST_FIXTURE_TEST_CASE(kosaraju_simple_test_1, GraphTestFixture) {
  directedIntGraph.addVertex(1);
  directedIntGraph.addVertex(2);
  directedIntGraph.addVertex(3);
  directedIntGraph.addVertex(4);
  directedIntGraph.addEdge(1, 2);
  directedIntGraph.addEdge(2, 3);
  directedIntGraph.addEdge(3, 1);
  directedIntGraph.addEdge(1, 4);
  directedIntGraph.addEdge(3, 4);

  graph::KosarajuSCCFinder<int> kosarajuSCCFinder(directedIntGraph);

  std::vector<std::vector<int>> sccs = kosarajuSCCFinder.computeSCCs();

  for (auto scc : sccs) {
    LOG_INFO << logging::str(scc);
  }
}

/**
 * Kosaraju's algorithm for finding strongly connected components
 */
BOOST_FIXTURE_TEST_CASE(kosaraju_simple_test_2, GraphTestFixture) {
  directedIntGraph.addVertex(0);
  directedIntGraph.addVertex(1);
  directedIntGraph.addVertex(2);
  directedIntGraph.addVertex(3);
  directedIntGraph.addVertex(4);
  directedIntGraph.addEdge(0, 2);
  directedIntGraph.addEdge(2, 1);
  directedIntGraph.addEdge(1, 0);
  directedIntGraph.addEdge(0, 3);
  directedIntGraph.addEdge(3, 4);

  graph::KosarajuSCCFinder<int> kosarajuSCCFinder(directedIntGraph);

  std::vector<std::vector<int>> sccs = kosarajuSCCFinder.computeSCCs();

  for (auto scc : sccs) {
    LOG_INFO << logging::str(scc);
  }
}