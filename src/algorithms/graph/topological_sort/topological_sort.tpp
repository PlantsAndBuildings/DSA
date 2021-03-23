#ifndef TOPOSORT_TPP
#define TOPOSORT_TPP

#include "./topological_sort.hpp"

template <typename T>
graph::TopologicalSorter<T>::TopologicalSorter(DirectedGraph<T> graph) {
  this->graph = graph;
}

template <typename T> std::vector<T> graph::TopologicalSorter<T>::sort() {
  std::unordered_map<T, bool> visited;
  std::stack<T> dfsTreeTraversalStack;
  for (auto vertex : this->graph.getVertices()) {
    if (!visited[vertex]) {
      this->topoSortUtil(vertex, visited, dfsTreeTraversalStack);
    }
  }
  std::vector<T> topoSort;
  while (!dfsTreeTraversalStack.empty()) {
    topoSort.push_back(dfsTreeTraversalStack.top());
    dfsTreeTraversalStack.pop();
  }

  return topoSort;
}

template <typename T>
void graph::TopologicalSorter<T>::topoSortUtil(
    T source, std::unordered_map<T, bool> &visited,
    std::stack<T> &dfsTreeTraversalStack) {
  visited[source] = true;

  for (T vertex : this->graph.getAdjacencyList()[source]) {
    if (!visited[vertex])
      topoSortUtil(vertex, visited, dfsTreeTraversalStack);
  }
  dfsTreeTraversalStack.push(source);
}

#endif