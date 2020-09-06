#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

/**
 * \brief Sorter that implements bubble sort
 *
 * Bubble sort is a popular sorting algorithm which runs in O(N^2) time where N
 * represents the length of the array. The idea behind bubble sort is to
 * iterate over an array while comparing adjacent elements and swapping them
 * if they are in the wrong order. The array must be iterated over N times for
 * it to be completely sorted. Please refer to any text on algorithms
 * (preferably Introduction to Algorithms by Cormen et al) for complete details.
 *
 * This class extends from the \ref sorting::Sorter_t "Sorter" abstract class
 * and implements the \ref sorting::Sorter_t::sort() "sort()" pure function.
 *
 * \tparam T type of data to be sorted
 */
template <typename T> class BubbleSorter_t : public Sorter_t<T> {
public:
  /**
   * \brief Implementation of bubble sort for generic type. Please check \ref
   * bubble_sort.cpp for specializations of this function.
   *
   * \tparam T type of data to be sorted
   *
   * \param list input list to be sorted
   */
  void sort(vector<T> &list);

private:
  /**
   * \brief utility method to sort a vector containing numeric data types using
   * bubble sort
   *
   * The \ref sorting::BubbleSorter_t::sort() "sort()" public method has a
   * number of template specializations present in \ref bubble_sort.cpp
   * "bubble_sort.cpp". All the specializations for numeric data types like
   * `int`, `long`, `float`, `double` etc will have the exact same
   * implementation of bubble sort. This method caters to all such template
   * specializations.
   *
   * \param list input list to be sorted using bubble sort
   *
   * \param begIdx beginning index for the range of input list that needs to be
   * sorted
   *
   * \param endIdx end index for the range of input list that needs to be sorted
   */
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using BubbleSorter = BubbleSorter_t<T> &;
} // namespace sorting

#include "bubble_sort.tpp"

#endif
