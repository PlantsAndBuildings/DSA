#include "heap_sort.hpp"
#include <iostream>

using sorting::HeapSorter_t;

template <> void HeapSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::HeapSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void HeapSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::HeapSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void HeapSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::HeapSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void HeapSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::HeapSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void HeapSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::HeapSorter_t<long long>::sortUtilNumeric(list, 0, list.size() - 1);
}
