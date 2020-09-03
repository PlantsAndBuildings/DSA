#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

template <typename T> class SelectionSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, unsigned int, unsigned int);
};

template <typename T> using SelectionSorter = SelectionSorter_t<T> &;
} // namespace sorting

#include "selection_sort.tpp"

#endif
