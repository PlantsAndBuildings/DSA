#ifndef UNDIRECTED_GRAPH_TPP
#define UNDIRECTED_GRAPH_TPP

#include "../../../utils/boost/logging_utils.hpp"
#include "./undirected_graph.hpp"

template <typename T> void graph::UndirectedGraph<T>::addVertex(T vertex) {
  LOG_DEBUG << "Add Vertex";
}

template <typename T>
void graph::UndirectedGraph<T>::addEdge(T vertex1, T vertex2) {
  LOG_DEBUG << "Add Edge";
}

#endif