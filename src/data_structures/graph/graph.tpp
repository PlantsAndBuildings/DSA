#ifndef GRAPH_TPP
#define GRAPH_TPP

#include "graph.hpp"

template <typename T>
std::unordered_map<T, std::vector<T>>& graph::Graph<T>::getAdjacencyList() {
  return this->adjacencyList;
}

template <typename T> std::vector<T> graph::Graph<T>::getVertices() {
  return this->vertices;
}

template <typename T> void graph::Graph<T>::print() {
  LOG_DEBUG << "=================";
  LOG_DEBUG << "Graph(V: " << this->vertices.size()
            << ", E: " << this->edges.size() << ")";
  LOG_DEBUG << "";
  for (auto vertex : this->vertices) {
    std::string curLog = std::to_string(vertex) + " -> (";
    for (auto adjVertex : this->adjacencyList[vertex]) {
      curLog.append(std::to_string(adjVertex) + ", ");
    }
    curLog.append(")");
    LOG_DEBUG << curLog;
  }
  LOG_DEBUG << "=================";
}

#endif