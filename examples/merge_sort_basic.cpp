#include "../src/algorithms/sorting/sorter.hpp"
#include "../src/algorithms/sorting/sorter_factory.hpp"
#include "../src/algorithms/sorting/sorting_algorithm.hpp"
#include <iostream>
#include <vector>

int main() {
  // std::vector<std::string> v = vector<std::string>(3, "Daivik");
  std::vector<int> v = vector<int>(3, 0);
  v[0] = 3;
  v[1] = 2;
  v[2] = 1;
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  // sorting::Sorter<std::string> s =
  //     sorting::SorterFactory::getSorter<std::string>(
  //         sorting::SortingAlgorithm::MergeSort);
  sorting::Sorter<int> s = sorting::SorterFactory::getSorter<int>(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  sorting::SorterFactory::deleteSorter(s);
  return 0;
}
