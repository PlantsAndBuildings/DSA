#include "selection_sort.hpp"
#include <iostream>

using sorting::SelectionSorter_t;

template <> void SelectionSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::SelectionSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void SelectionSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::SelectionSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void SelectionSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::SelectionSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void SelectionSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::SelectionSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void SelectionSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::SelectionSorter_t<long long>::sortUtilNumeric(list, 0,
                                                         list.size() - 1);
}
