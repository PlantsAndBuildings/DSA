#ifndef SORTER_FACTORY_HPP
#define SORTER_FACTORY_HPP

#include "merge_sort/merge_sort.hpp"
#include "sorter.hpp"
#include "sorting_algorithm.hpp"
#include <iostream>
#include <string>

using std::string;

namespace sorting {
class SorterFactory final {
public:
  template <typename T> static Sorter<T> getSorter(SortingAlgorithm);

  // static void deleteSorter(Sorter);
};
} // namespace sorting

#include "sorter_factory.tpp"

#endif
