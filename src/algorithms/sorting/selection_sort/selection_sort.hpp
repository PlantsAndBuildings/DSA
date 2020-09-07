#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

/**
 * \brief Sorter that implements selection sort
 *
 * Selection sort is a popular sorting algorithm which runs in O(N^2) time where
 * N represents the length of the array. The idea behind selection sort is to
 * iterate over the input array while maintaining the invariant that all the
 * elements seen up to a specific iteration are in sorted order. At every
 * iteration, we check over the non-sorted part of the array to find the element
 * that should be placed in the position currently being considered. Please
 * refer to any text on algorithms (preferably Introduction to Algorithms by
 * Cormen et al) for complete details.
 *
 * This class extends from the \ref sorting::Sorter_t "Sorter" abstract class
 * and implements the \ref sorting::Sorter_t::sort() "sort()" pure function.
 *
 * \tparam T type of data to be sorted
 */
template <typename T> class SelectionSorter_t : public Sorter_t<T> {
public:
  /**
   * \brief Implementation of selection sort for generic type. Please check \ref
   * selection_sort.cpp for specializations of this function.
   *
   * \tparam T type of data to be sorted
   *
   * \param list input list to be sorted
   */
  void sort(vector<T> &);

private:
  /**
   * \brief utility method to sort a vector containing numeric data types using
   * selection sort
   *
   * The \ref sorting::SelectionSorter_t::sort() "sort()" public method has a
   * number of template specializations present in \ref selection_sort.cpp
   * "selection_sort.cpp". All the specializations for numeric data types like
   * `int`, `long`, `float`, `double` etc will have the exact same
   * implementation of selection sort. This method caters to all such template
   * specializations.
   *
   * \param list input list to be sorted using selection sort
   *
   * \param begIdx beginning index for the range of input list that needs to be
   * sorted
   *
   * \param endIdx end index for the range of input list that needs to be sorted
   */
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using SelectionSorter = SelectionSorter_t<T> &;
} // namespace sorting

#include "selection_sort.tpp"

#endif
