#ifndef GRAPH_TPP
#define GRAPH_TPP

#include "graph.hpp"

template <typename T>
std::unordered_map<T, std::vector<T>> &graph::Graph<T>::getAdjacencyList() {
  return this->adjacencyList;
}

template <typename T> std::vector<T> graph::Graph<T>::getVertices() {
  return this->vertices;
}

template <typename T> std::vector<std::pair<T, T>> graph::Graph<T>::getEdges() {
  return this->edges;
}

template <typename T> void graph::Graph<T>::print() {
  LOG_DEBUG << "=================";
  LOG_DEBUG << "Graph(V: " << this->vertices.size()
            << ", E: " << this->edges.size() << ")";
  LOG_DEBUG << "";
  for (auto vertex : this->vertices) {
    LOG_DEBUG << vertex << " -> " << logging::str(adjacencyList[vertex]);
  }
  LOG_DEBUG << "=================";
}

#endif