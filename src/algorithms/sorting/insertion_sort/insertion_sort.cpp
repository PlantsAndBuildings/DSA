/**
 * \file insertion_sort.cpp
 *
 * Insertion sort implementation for specialized types
 */
#include "insertion_sort.hpp"
#include <iostream>

using sorting::InsertionSorter_t;

template <> void InsertionSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::InsertionSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void InsertionSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::InsertionSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void InsertionSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::InsertionSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void InsertionSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::InsertionSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void InsertionSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::InsertionSorter_t<long long>::sortUtilNumeric(list, 0,
                                                         list.size() - 1);
}
