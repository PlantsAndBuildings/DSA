#include "../src/algorithms/sorting/sorter_factory.hpp"
#include "../src/algorithms/sorting/sorting_algorithm.hpp"
#include "../src/algorithms/sorting/sorter.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = vector<int>(3, 0);
  sorting::Sorter s = sorting::SorterFactory::getSorter(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  sorting::SorterFactory::deleteSorter(s);
  return 0;
}
