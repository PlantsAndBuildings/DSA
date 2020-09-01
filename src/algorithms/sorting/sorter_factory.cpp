#include "sorter.hpp"
#include "sorter_factory.hpp"
#include "merge_sort/merge_sort.hpp"
#include "sorting_algorithm.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using sorting::SorterFactory;
using sorting::MergeSorter;
using sorting::Sorter;

Sorter SorterFactory::getSorter(SortingAlgorithm sortingAlgorithm) {
  MergeSorter_t * m = new MergeSorter_t();
  cout << "getSorter(char*) called" << endl;
  return *m;
}


void SorterFactory::deleteSorter(Sorter sorter) {
  delete &sorter;
}
