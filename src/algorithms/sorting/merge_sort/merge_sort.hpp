#ifndef MERGE_SORT
#define MERGE_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>

namespace sorting {

/**
 * \brief Sorter that implements merge sort
 *
 * Merge sort is a popular sorting algorithm which runs in O(N*lg(N)) time where
 * N represents the length of the array. The idea is that merging two already
 * sorted arrays can be done in linear time as follows: Compare the first
 * elements of both arrays and remove whichever one is smallest and add it to
 * the result array. Repeat this till both arrays are empty. In mergesort, we
 * leverage this linear time merge subroutine. We divide our input array into
 * two halves and recursively call merge sort on each half. Then we use the
 * merge subroutine to merge both halves. Therefore, T(N) = 2*T(N/2) + O(N).
 * This recurrence can be solved to give the overall time complexity of
 * mergesort as O(N*lg(N)). Please refer to any text on algorithms (preferably
 * Introduction to Algorithms by Cormen et al) for complete details.
 *
 * This class extends from the \ref sorting::Sorter_t "Sorter" abstract class
 * and implements the \ref sorting::Sorter_t::sort() "sort()" pure function.
 *
 * \tparam T type of data to be sorted
 */
template <typename T> class MergeSorter_t : public Sorter_t<T> {
public:
  /**
   * \brief Implementation of merge sort for generic type. Please check \ref
   * merge_sort.cpp for specializations of this function.
   *
   * \tparam T type of data to be sorted
   *
   * \param list input list to be sorted
   */
  void sort(vector<T> &);

private:
  /**
   * \brief utility method to sort a vector containing numeric data types using
   * merge sort
   *
   * The \ref sorting::MergeSorter_t::sort() "sort()" public method has a
   * number of template specializations present in \ref merge_sort.cpp
   * "merge_sort.cpp". All the specializations for numeric data types like
   * `int`, `long`, `float`, `double` etc will have the exact same
   * implementation of merge sort. This method caters to all such template
   * specializations.
   *
   * \param list input list to be sorted using merge sort
   *
   * \param begIdx beginning index for the range of input list that needs to be
   * sorted
   *
   * \param endIdx end index for the range of input list that needs to be sorted
   */
  void sortUtilNumeric(vector<T> &list, int begIdx, int endIdx);

  /**
   * \brief utility method for merging two sorted arrays containing nuric data
   *
   * As noted in the description of the \ref sorting::MergeSorter_t::sort()
   * "sort()" method, merge sort algorithm relies on the fact that two sorted
   * arrays can be merged in linear time. This method implements that merge
   * subroutine for numeric types. This method is called to merge the sorted
   * ranges list[begIdx..midIdx] and list[midIdx+1..endIdx]
   *
   * \param list vector to be sorted
   *
   * \param begIdx beginning of first range
   *
   * \param midIdx end of first range. Second range starts from midIdx+1
   *
   * \param endIdx end of second range
   */
  void mergeUtilNumeric(vector<T> &list, int begIdx, int midIdx, int endIdx);
};

template <typename T> using MergeSorter = MergeSorter_t<T> &;
} // namespace sorting

#include "merge_sort.tpp"

#endif
