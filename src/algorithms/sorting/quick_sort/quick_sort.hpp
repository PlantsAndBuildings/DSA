#ifndef QUICK_SORT
#define QUICK_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>
#include <random>

namespace sorting {

/**
 * \brief Sorter that implements quick sort
 *
 * Quick sort is a popular sorting algorithm which runs in O(N*lg(N)) time where
 * N represents the length of the array. The idea behind quick sort is to select
 * a pivot element and partition the array into two parts - one part containing
 * all the array elements less than the pivot; and the other containing all the
 * array elements greater than the pivot. Then, quicksort is called recursively
 * on each of the two parts. Please refer to any text on algorithms (preferably
 * Introduction to Algorithms by Cormen et al) for complete details.
 *
 * This class extends from the \ref sorting::Sorter_t "Sorter" abstract class
 * and implements the \ref sorting::Sorter_t::sort() "sort()" pure function.
 *
 * \tparam T type of data to be sorted
 */
template <typename T> class QuickSorter_t : public Sorter_t<T> {
public:
  /**
   * \brief Implementation of quick sort for generic type. Please check \ref
   * quick_sort.cpp for specializations of this function.
   *
   * \tparam T type of data to be sorted
   *
   * \param list input list to be sorted
   */
  void sort(vector<T> &);

private:
  /**
   * \brief utility method to sort a vector containing numeric data types using
   * quick sort
   *
   * The \ref sorting::QuickSorter_t::sort() "sort()" public method has a
   * number of template specializations present in \ref quick_sort.cpp
   * "quick_sort.cpp". All the specializations for numeric data types like
   * `int`, `long`, `float`, `double` etc will have the exact same
   * implementation of quick sort. This method caters to all such template
   * specializations.
   *
   * \param list input list to be sorted using quick sort
   *
   * \param begIdx beginning index for the range of input list that needs to be
   * sorted
   *
   * \param endIdx end index for the range of input list that needs to be sorted
   */
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using QuickSorter = QuickSorter_t<T> &;

#include "quick_sort.tpp"

} // namespace sorting

#endif
