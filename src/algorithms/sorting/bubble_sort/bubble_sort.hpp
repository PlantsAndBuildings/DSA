#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

template <typename T> class BubbleSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, unsigned int, unsigned int);
};

template <typename T> using BubbleSorter = BubbleSorter_t<T> &;
} // namespace sorting

#include "bubble_sort.tpp"

#endif
