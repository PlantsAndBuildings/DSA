#ifndef DFS_TPP
#define DFS_TPP

#include "./dfs.hpp"

template <typename T>
graph::DepthFirstTraverser<T>::DepthFirstTraverser(
    graph::UndirectedGraph<T> graph) {
  this->graph = graph;
}

template <typename T> void graph::DepthFirstTraverser<T>::traverse() {
  const std::function<void(T)> &printOp = [](T node) -> void {
    LOG_INFO << node;
  };
  this->traverse(printOp);
}

template <typename T>
void graph::DepthFirstTraverser<T>::traverse(
    const std::function<void(T)> &operation) {
  std::unordered_map<T, bool> visited;
  for (T vertex : (this->graph.getVertices())) {
    if (!visited[vertex]) {
      this->traverseUtil(vertex, visited, operation);
    }
  }
}

template <typename T>
void graph::DepthFirstTraverser<T>::traverseUtil(
    T source, std::unordered_map<T, bool> &visited,
    const std::function<void(T)> &operation) {
  visited[source] = true;

  for (auto adjacentVertex : this->graph.getAdjacencyList()[source]) {
    if (!visited[adjacentVertex])
      traverseUtil(adjacentVertex, visited, operation);
  }

  operation(source);
}

#endif