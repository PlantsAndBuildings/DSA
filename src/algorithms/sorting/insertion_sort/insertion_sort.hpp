#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

template <typename T> class InsertionSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using InsertionSorter = InsertionSorter_t<T> &;
} // namespace sorting

#include "insertion_sort.tpp"

#endif
