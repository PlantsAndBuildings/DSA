/**
 * \file merge_sort.cpp
 *
 * Merge sort implementation for specialized types
 */
#include "merge_sort.hpp"
#include <iostream>

using sorting::MergeSorter_t;

template <> void MergeSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::MergeSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void MergeSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::MergeSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void MergeSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::MergeSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void MergeSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::MergeSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void MergeSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::MergeSorter_t<long long>::sortUtilNumeric(list, 0, list.size() - 1);
}
