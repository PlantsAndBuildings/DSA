/**
 * \file quick_sort.cpp
 *
 * Quick sort implementation for specialized types
 */
#include "quick_sort.hpp"
#include <iostream>

using sorting::QuickSorter_t;

template <> void QuickSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void QuickSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void QuickSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void QuickSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void QuickSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<long long>::sortUtilNumeric(list, 0, list.size() - 1);
}
