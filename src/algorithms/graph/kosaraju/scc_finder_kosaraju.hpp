#ifndef SCC_FINDER_KOSARAJU_HPP
#define SCC_FINDER_KOSARAJU_HPP

#include "../../../data_structures/graph/directed_graph.hpp"
#include <stack>
#include <vector>

namespace graph {
template <typename T> class KosarajuSCCFinder {
private:
  DirectedGraph<T> graph;

  void computeVerticesCompletion(T source, std::unordered_map<T, bool> &visited,
                                 std::stack<T> &discTimeStack);

  void extractSCC(DirectedGraph<T> &transposeGraph, T source,
                  std::unordered_map<T, bool> &visited, std::vector<T> &scc);

public:
  KosarajuSCCFinder(DirectedGraph<T> graph);

  std::vector<std::vector<T>> computeSCCs();
};
} // namespace graph

#include "./scc_finder_kosaraju.tpp"

#endif