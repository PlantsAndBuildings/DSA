#ifndef DFS_HPP
#define DFS_HPP

#include "../../../../utils/boost/logging_utils.hpp"
#include "../../../data_structures/graph/undirected_graph.hpp"
#include <functional>
#include <unordered_map>

namespace graph {
template <typename T> class DepthFirstTraverser {
private:
  UndirectedGraph<T> graph;

  void traverseUtil(T source, std::unordered_map<T, bool> &visited,
                    const std::function<void(T)> &operation);

public:
  DepthFirstTraverser(UndirectedGraph<T> graph);

  void traverse();

  void traverse(const std::function<void(T)> &operation);
};
} // namespace graph

#include "dfs.tpp"

#endif