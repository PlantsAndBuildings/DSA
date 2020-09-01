#ifndef SORTER_FACTORY_HPP
#define SORTER_FACTORY_HPP

#include <string>
#include "sorter.hpp"
#include "sorting_algorithm.hpp"

using std::string;

namespace sorting {
class SorterFactory final {
  public:
    static Sorter getSorter(SortingAlgorithm);
    static void deleteSorter(Sorter);
};
}

#endif
