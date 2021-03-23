#ifndef TOPOSORT_HPP
#define TOPOSORT_HPP

#include "../../../data_structures/graph/directed_graph.hpp"
#include <stack>
#include <unordered_map>
#include <vector>

namespace graph {
template <typename T> class TopologicalSorter {
private:
  DirectedGraph<T> graph;

  void topoSortUtil(T vertex, std::unordered_map<T, bool> &visited,
                    std::stack<T> &dfsTreeTraversalStack);

public:
  TopologicalSorter(DirectedGraph<T> graph);

  std::vector<T> sort();
};
} // namespace graph

#include "topological_sort.tpp"

#endif