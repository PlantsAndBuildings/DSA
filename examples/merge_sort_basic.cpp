#include "../src/algorithms/sorting/sorter_factory.hpp"
#include "../src/algorithms/sorting/sorting_algorithm.hpp"
#include "../src/algorithms/sorting/sorter.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> v = vector<std::string>(3, "Daivik");
  // std::vector<int> v = vector<int>(3, 0);
  sorting::Sorter<std::string> s = sorting::SorterFactory::getSorter<std::string>(sorting::SortingAlgorithm::MergeSort);
  // sorting::Sorter<int> s = sorting::SorterFactory::getSorter<int>(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  // sorting::SorterFactory::deleteSorter(s);
  return 0;
}
