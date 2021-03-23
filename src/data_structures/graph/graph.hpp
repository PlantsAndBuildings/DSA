#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../../../utils/boost/logging_utils.hpp"
#include <unordered_map>
#include <vector>

namespace graph {

template <typename T> class Graph {
protected:
  std::unordered_map<T, std::vector<T>> adjacencyList;
  std::vector<std::pair<T, T>> edges;
  std::vector<T> vertices;

public:
  void print();
  Graph(){};

  virtual void addVertex(T v1) = 0;

  virtual void addEdge(T v1, T v2) = 0;

  std::unordered_map<T, std::vector<T>> &getAdjacencyList();

  std::vector<T> getVertices();

  std::vector<std::pair<T, T>> getEdges();

  virtual ~Graph(){};
};

#include "graph.tpp"

} // namespace graph

#endif
