#ifndef MERGE_SORT
#define MERGE_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

template <typename T> class MergeSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, unsigned int, unsigned int);
  void mergeUtilNumeric(vector<T> &, unsigned int, unsigned int, unsigned int);
};

template <typename T> using MergeSorter = MergeSorter_t<T> &;
} // namespace sorting

#include "merge_sort.tpp"

#endif
