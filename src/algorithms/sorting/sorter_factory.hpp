#ifndef SORTER_FACTORY_HPP
#define SORTER_FACTORY_HPP

#include <string>
#include <iostream>
#include "sorter.hpp"
#include "sorting_algorithm.hpp"
#include "merge_sort/merge_sort.hpp"

using std::string;

namespace sorting {
class SorterFactory final {
  public:
    template <typename T>
    static Sorter<T> getSorter(SortingAlgorithm);

    // static void deleteSorter(Sorter);
};
}

#include "sorter_factory.tpp"

#endif
