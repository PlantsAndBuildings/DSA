#include "bubble_sort.hpp"
#include <iostream>

using sorting::BubbleSorter_t;

template <> void BubbleSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::BubbleSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void BubbleSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::BubbleSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void BubbleSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::BubbleSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void BubbleSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::BubbleSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

template <> void BubbleSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::BubbleSorter_t<long long>::sortUtilNumeric(list, 0, list.size() - 1);
}
