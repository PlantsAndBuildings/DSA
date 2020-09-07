#ifndef HEAP_SORT
#define HEAP_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../../../data_structures/heap/heap.hpp"
#include "../../../data_structures/heap/heap_type.hpp"
#include "../sorter.hpp"
#include <iostream>
#include <limits>

namespace sorting {

/**
 * \brief Sorter that implements heap sort
 *
 * Heap sort is a popular sorting algorithm which runs in O(N*lg(N)) time where
 * N represents the length of the array. The idea is to create a \ref Heap
 * "Heap" data structure using the input array. Then repeatedly extract the top
 * of the heap (till it is empty) to obtain the elements in sorted order.
 * Building a heap can be achieved in O(N) time. Repeatedly extracting till the
 * heap is empty takes O(N*lg(N)) time. Thus the overall time complexity is
 * O(N*lg(N)). Please refer to any text on algorithms (preferably Introduction
 * to Algorithms by Cormen et al) for complete details.
 *
 * This class extends from the \ref sorting::Sorter_t "Sorter" abstract class
 * and implements the \ref sorting::Sorter_t::sort() "sort()" pure function.
 *
 * \tparam T type of data to be sorted
 */
template <typename T> class HeapSorter_t : public Sorter_t<T> {
public:
  /**
   * \brief Implementation of heap sort for generic type. Please check \ref
   * heap_sort.cpp for specializations of this function.
   *
   * \tparam T type of data to be sorted
   *
   * \param list input list to be sorted
   */
  void sort(vector<T> &);

private:
  /**
   * \brief utility method to sort a vector containing numeric data types using
   * heap sort
   *
   * The \ref sorting::HeapSorter_t::sort() "sort()" public method has a
   * number of template specializations present in \ref heap_sort.cpp
   * "heap_sort.cpp". All the specializations for numeric data types like
   * `int`, `long`, `float`, `double` etc will have the exact same
   * implementation of heap sort. This method caters to all such template
   * specializations.
   *
   * \param list input list to be sorted using heap sort
   *
   * \param begIdx beginning index for the range of input list that needs to be
   * sorted
   *
   * \param endIdx end index for the range of input list that needs to be sorted
   */
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using HeapSorter = HeapSorter_t<T> &;

} // namespace sorting

#include "heap_sort.tpp"

#endif
