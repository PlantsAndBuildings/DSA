#include "../src/algorithms/sorting/sorter.hpp"
#include "../src/algorithms/sorting/sorter_factory.hpp"
#include "../src/algorithms/sorting/sorting_algorithm.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <iostream>
#include <vector>
#include <boost/log/trivial.hpp>

void sortInts() {
  std::vector<int> v = {3, 2, 1};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<int> s = sorting::SorterFactory::getSorter<int>(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

void sortDoubles() {
  std::vector<double> v = {3.234, 4.567, 1.03};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<double> s = sorting::SorterFactory::getSorter<double>(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

void sortStrings() {
  std::vector<std::string> v = {"Robert Plant", "Jimmy Page", "John Bonham"};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<std::string> s = sorting::SorterFactory::getSorter<std::string>(sorting::SortingAlgorithm::MergeSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

int main() {
  logging::loggerInit("INFO");
  sortInts();
  sortDoubles();
  sortStrings();
  return 0;
}
