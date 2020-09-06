/**
 * \file insertion_sort_basic.cpp
 * \brief Example program for sorting numeric types using insertion sort
 * \see sorting::InsertionSorter_t
 */
#include "../src/algorithms/sorting/sorter.hpp"
#include "../src/algorithms/sorting/sorter_factory.hpp"
#include "../src/algorithms/sorting/sorting_algorithm.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <boost/log/trivial.hpp>
#include <iostream>
#include <vector>

/**
 * Example for sorting an vector of ints
 */
void sortInts() {
  std::vector<int> v = {3, 2, 1};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<int> s = sorting::SorterFactory::getSorter<int>(
      sorting::SortingAlgorithm::InsertionSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

/**
 * Example for sorting an vector of doubles
 */
void sortDoubles() {
  std::vector<double> v = {3.234, 4.567, 1.03};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<double> s = sorting::SorterFactory::getSorter<double>(
      sorting::SortingAlgorithm::InsertionSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

/**
 * Example for sorting an vector of strings
 */
void sortStrings() {
  std::vector<std::string> v = {"Robert Plant", "Jimmy Page", "John Bonham"};
  LOG_INFO << "Initial array: " << logging::str(v);
  sorting::Sorter<std::string> s =
      sorting::SorterFactory::getSorter<std::string>(
          sorting::SortingAlgorithm::InsertionSort);
  s.sort(v);
  LOG_INFO << "Final array: " << logging::str(v);
  sorting::SorterFactory::deleteSorter(s);
}

/**
 * driver function
 */
int main() {
  logging::loggerInit("INFO");
  sortInts();
  sortDoubles();
  sortStrings();
  return 0;
}
