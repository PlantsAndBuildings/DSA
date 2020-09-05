#ifndef HEAP_SORT_TPP
#define HEAP_SORT_TPP

#include "../../../data_structures/heap/heap.hpp"
#include <vector>

template <typename T> void sorting::HeapSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using heap sort not implemented!";
  // TODO
  // Heap<T> heap(list);
  // unsigned int idx = list.size() - 1;
  // while (!heap.empty()) {
  //   T top = heap.extractTop();
  //   LOG_DEBUG << "Heap top: " << top;
  //   list[idx--] = top;
  // }
}

template <typename T>
void sorting::HeapSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                               int endIdx) {
  Heap<T> heap(list);
  unsigned int idx = endIdx;
  while (!heap.empty()) {
    T top = heap.extractTop();
    LOG_DEBUG << "Heap top: " << top;
    list[idx--] = top;
  }
}

#endif
