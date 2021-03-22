#ifndef UNDIRECTED_GRAPH_HPP
#define UNDIRECTED_GRAPH_HPP

#include "./graph.hpp"

namespace graph {
template <typename T> class UndirectedGraph : public Graph<T> {
public:
  UndirectedGraph() {}

  ~UndirectedGraph() {}

  void addVertex(T v1);
  void addEdge(T v1, T v2);
};
}; // namespace graph

#include "./undirected_graph.tpp"

#endif