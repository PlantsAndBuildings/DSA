#include "sorter_factory.hpp"
#include "merge_sort/merge_sort.hpp"
#include "sorter.hpp"
#include "sorting_algorithm.hpp"
#include <iostream>

using sorting::MergeSorter;
using sorting::Sorter;
using sorting::SorterFactory;
using std::cout;
using std::endl;
using std::string;

// template <typename T>
// Sorter<T> SorterFactory::getSorter(SortingAlgorithm sortingAlgorithm) {
//   MergeSorter_t<T> * m = new MergeSorter_t<T>();
//   cout << "getSorter<T>() called" << endl;
//   return *m;
// }

// template <>
// Sorter<std::string> SorterFactory::getSorter(SortingAlgorithm
// sortingAlgorithm) {
//   MergeSorter_t<std::string> * m = new MergeSorter_t<std::string>();
//   cout << "getSorter<std::string>() called!" << endl;
//   return *m;
// }

template <>
Sorter<int> SorterFactory::getSorter(SortingAlgorithm sortingAlgorithm) {
  MergeSorter_t<int> *m = new MergeSorter_t<int>();
  cout << "getSorter<int>() called!" << endl;
  return *m;
}

template <>
Sorter<long long> SorterFactory::getSorter(SortingAlgorithm sortingAlgorithm) {
  MergeSorter_t<long long> *m = new MergeSorter_t<long long>();
  cout << "getSorter<long long>() called!" << endl;
  return *m;
}

// void SorterFactory::deleteSorter(Sorter sorter) {
//   delete &sorter;
// }
