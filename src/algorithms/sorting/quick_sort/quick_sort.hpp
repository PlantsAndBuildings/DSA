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

template <typename T> void QuickSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using quick sort not implemented!";
}

template <typename T>
void QuickSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                       int endIdx) {
  // N denotes the size of the range that needs to be sorted
  int N = endIdx - begIdx + 1;

  // Handle base cases
  if (N <= 0 || N == 1)
    return;

  // Pivot element is selected randomly from the range. This is some boilerplate
  // code for generating the pivot randomly
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(begIdx, endIdx);

  // Select the pivot randomly from the range list[begIdx..endIdx]
  int pivotIdx = distrib(gen);
  T pivot = list[pivotIdx];

  // We want to partition the list[begIdx..endIdx] as follows:
  // 1. list[begIdx .. smallIdx] < pivot
  // 2. list[smallIdx+1 .. bigIdx - 1] == pivot
  // 3. list[bigIdx .. endIdx] > pivot

  // Initialize smallIdx and bigIdx
  int smallIdx = begIdx - 1;
  int bigIdx = endIdx + 1;

  // We will use idx to iterate over the array range
  int idx = begIdx;

  // idx is used to iterate through list[begIdx..endIdx]
  // At every iteration, we will check whether list[idx] is less than; greater
  // than; or equal to the pivot element All the list elements within the range
  // that are less than the pivot element will be moved to the beginning of the
  // range. Ie. list[begIdx..smallIdx] will contain all the elements in range
  // smaller than the pivot Similarly, all the list elements within the range
  // that are greater than the pivot will be moved to the end of the range. Ie.
  // list[bigIdx..endIdx] will contain all the elements in the range greater
  // than the pivot list[smallIdx+1..bigIdx-1] will contain list elements ==
  // pivot Once we have achieved the partitioning descibed above, we can run
  // this method recursively on subranges list[begIdx..smallIdx] and
  // list[bigIdx..endIdx]
  while (bigIdx > smallIdx && bigIdx >= begIdx && smallIdx <= endIdx &&
         idx < bigIdx) {
    if (list[idx] < pivot) {
      smallIdx++;
      idx++;
    } else if (list[idx] > pivot) {
      // swap list[idx] and list[bigIdx - 1]
      T tmp = list[idx];
      list[idx] = list[bigIdx - 1];
      list[bigIdx - 1] = tmp;

      // decrement bigIdx
      bigIdx--;
    } else {
      // increment only idx
      idx++;
    }
  }
  // At the end of the above loop:
  // 1. list[begIdx .. smallIdx] < pivot
  // 2. list[smallIdx+1 .. bigIdx - 1] == pivot
  // 3. list[bigIdx .. endIdx] > pivot

  // Run quicksort on list[begIdx .. smallIdx] and list[bigIdx .. endIdx]
  this->sortUtilNumeric(list, begIdx, smallIdx);
  this->sortUtilNumeric(list, bigIdx, endIdx);
}

} // namespace sorting

#endif
