#ifndef DIRECTED_GRAPH_TPP
#define DIRECTED_GRAPH_TPP

#include "../../../utils/boost/logging_utils.hpp"
#include "./directed_graph.hpp"

template <typename T> void graph::DirectedGraph<T>::addVertex(T vertex) {
  if (this->adjacencyList.find(vertex) != this->adjacencyList.end()) {
    LOG_ERROR << "Cannot add vertex: " << vertex << ". Already exists!";
    return;
  }

  this->vertices.push_back(vertex);
  this->adjacencyList[vertex] = std::vector<T>();
}

template <typename T>
void graph::DirectedGraph<T>::addEdge(T vertex1, T vertex2) {
  if (this->adjacencyList.find(vertex1) == this->adjacencyList.end()) {
    LOG_ERROR << "Couldn't find vertex: " << vertex1 << ". Add edge failed!";
    return;
  }
  if (this->adjacencyList.find(vertex2) == this->adjacencyList.end()) {
    LOG_ERROR << "Couldn't find vertex: " << vertex2 << ". Add edge failed!";
    return;
  }

  this->adjacencyList[vertex1].push_back(vertex2);
  this->edges.push_back(std::pair<T, T>(vertex1, vertex2));

  // Uncomment for debug log
  // this->print();
}

#endif