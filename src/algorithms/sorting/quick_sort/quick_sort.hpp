#ifndef QUICK_SORT
#define QUICK_SORT

#include "../../../../utils/boost/logging_utils.hpp"
#include "../sorter.hpp"
#include <iostream>
#include <random>

namespace sorting {

template <typename T> class QuickSorter_t : public Sorter_t<T> {
public:
  void sort(vector<T> &);

private:
  void sortUtilNumeric(vector<T> &, int, int);
};

template <typename T> using QuickSorter = QuickSorter_t<T> &;

template <typename T> void QuickSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using quick sort not implemented!";
}

template <typename T>
void QuickSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                       int endIdx) {
  int N = endIdx - begIdx + 1;
  if (N <= 0 || N == 1)
    return;

  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(begIdx, endIdx);

  int pivotIdx = distrib(gen);
  T pivot = list[pivotIdx];

  int smallIdx = begIdx - 1;
  int bigIdx = endIdx + 1;
  int idx = begIdx;

  while (bigIdx > smallIdx && bigIdx >= begIdx && smallIdx <= endIdx &&
         idx < bigIdx) {
    if (list[idx] < pivot) {
      // increment smallIdx, bigIdx and idx
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
