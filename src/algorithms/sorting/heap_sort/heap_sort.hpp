#ifndef HEAP_SORT
#define HEAP_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../../../data_structures/heap/heap.hpp"
#include "../../../data_structures/heap/heap_type.hpp"
#include "../sorter.hpp"
#include <iostream>
#include <limits>

namespace sorting {

template <typename T> class HeapSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using HeapSorter = HeapSorter_t<T> &;

} // namespace sorting

#include "heap_sort.tpp"

#endif
