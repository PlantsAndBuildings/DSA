#ifndef UNDIRECTED_GRAPH_TPP
#define UNDIRECTED_GRAPH_TPP

#include "../../../utils/boost/logging_utils.hpp"
#include "./undirected_graph.hpp"

template <typename T> void graph::UndirectedGraph<T>::addVertex(T vertex) {
  if (this->adjacencyList.find(vertex) != this->adjacencyList.end()) {
    LOG_ERROR << "Cannot add vertex: " << vertex << ". Already exists!";
    return;
  }

  this->vertices.push_back(vertex);
  this->adjacencyList[vertex] = std::vector<T>();
}

template <typename T>
void graph::UndirectedGraph<T>::addEdge(T vertex1, T vertex2) {
  if (this->adjacencyList.find(vertex1) == this->adjacencyList.end()) {
    LOG_ERROR << "Couldn't find vertex: " << vertex1 << ". Add edge failed!";
    return;
  }
  if (this->adjacencyList.find(vertex2) == this->adjacencyList.end()) {
    LOG_ERROR << "Couldn't find vertex: " << vertex2 << ". Add edge failed!";
    return;
  }

  this->adjacencyList[vertex1].push_back(vertex2);
  this->adjacencyList[vertex2].push_back(vertex1);
  this->edges.push_back(std::pair<T, T>(vertex1, vertex2));

  // Uncomment for debug log
  // this->print();
}

#endif