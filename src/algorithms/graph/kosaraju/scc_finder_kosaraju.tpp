#ifndef SCC_FINDER_KOSARAJU_TPP
#define SCC_FINDER_KOSARAJU_TPP

#include "./scc_finder_kosaraju.hpp"

template <typename T>
graph::KosarajuSCCFinder<T>::KosarajuSCCFinder(DirectedGraph<T> graph) {
  this->graph = graph;
}

template <typename T>
std::vector<std::vector<T>> graph::KosarajuSCCFinder<T>::computeSCCs() {
  // Step 1: compute the ordering based on discovery time

  std::stack<T> verticesCompletion;
  std::unordered_map<T, bool> visited;
  for (auto vertex : this->graph.getVertices()) {
    if (!visited[vertex]) {
      this->computeVerticesCompletion(vertex, visited, verticesCompletion);
    }
  }

  // Step 2: compute the transpose graph

  DirectedGraph<T> transposeGraph;

  for (auto vertex : this->graph.getVertices()) {
    transposeGraph.addVertex(vertex);
  }

  for (auto edge : this->graph.getEdges()) {
    transposeGraph.addEdge(edge.second, edge.first);
  }

  // Step 3: In reverse order of discovery times, run DFS to obtain SCCs

  visited.clear();
  std::vector<std::vector<T>> sccs;
  while (!verticesCompletion.empty()) {
    T vertex = verticesCompletion.top();
    verticesCompletion.pop();

    if (!visited[vertex]) {
      std::vector<T> scc;
      this->extractSCC(transposeGraph, vertex, visited, scc);
      sccs.push_back(scc);
    }
  }

  return sccs;
}

template <typename T>
void graph::KosarajuSCCFinder<T>::computeVerticesCompletion(
    T source, std::unordered_map<T, bool> &visited,
    std::stack<T> &completionTimeStack) {
  visited[source] = true;

  for (auto vertex : this->graph.getAdjacencyList()[source]) {
    if (!visited[vertex]) {
      computeVerticesCompletion(vertex, visited, completionTimeStack);
    }
  }

  completionTimeStack.push(source);
}

template <typename T>
void graph::KosarajuSCCFinder<T>::extractSCC(
    DirectedGraph<T> &transposeGraph, T source,
    std::unordered_map<T, bool> &visited, std::vector<T> &scc) {
  visited[source] = true;
  scc.push_back(source);

  for (auto vertex : transposeGraph.getAdjacencyList()[source]) {
    if (!visited[vertex]) {
      extractSCC(transposeGraph, vertex, visited, scc);
    }
  }
}

#endif
