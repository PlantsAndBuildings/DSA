#ifndef SORTER_FACTORY_HPP
#define SORTER_FACTORY_HPP

#include "bubble_sort/bubble_sort.hpp"
#include "heap_sort/heap_sort.hpp"
#include "insertion_sort/insertion_sort.hpp"
#include "merge_sort/merge_sort.hpp"
#include "quick_sort/quick_sort.hpp"
#include "selection_sort/selection_sort.hpp"
#include "sorter.hpp"
#include "sorting_algorithm.hpp"
#include <iostream>
#include <string>

using std::string;

namespace sorting {
class SorterFactory final {
public:
  template <typename T> static Sorter<T> getSorter(SortingAlgorithm);

  template <typename T> static void deleteSorter(Sorter<T> &);
};
} // namespace sorting

#include "sorter_factory.tpp"

#endif
