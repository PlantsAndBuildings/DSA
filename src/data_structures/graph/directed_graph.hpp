#ifndef DIRECTED_GRAPH_HPP
#define DIRECTED_GRAPH_HPP

#include "./graph.hpp"

namespace graph {
template <typename T> class DirectedGraph : public Graph<T> {
public:
  DirectedGraph() {}

  ~DirectedGraph() {}

  void addVertex(T v1);
  void addEdge(T v1, T v2);
};
}; // namespace graph

#include "./directed_graph.tpp"

#endif