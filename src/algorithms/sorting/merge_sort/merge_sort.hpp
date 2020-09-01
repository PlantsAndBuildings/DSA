#ifndef MERGE_SORT
#define MERGE_SORT

#include "../sorter.hpp"
#include <iostream>

namespace sorting {

template <typename T> class MergeSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);
};

template <typename T> using MergeSorter = MergeSorter_t<T> &;
} // namespace sorting

#include "merge_sort.tpp"

#endif
