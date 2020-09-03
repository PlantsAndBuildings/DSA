#ifndef INSERTION_SORT_TPP
#define INSERTION_SORT_TPP

#include <limits>

template <typename T>
void sorting::InsertionSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using insertion sort not implemented!";
}

template <typename T>
void sorting::InsertionSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                                    int endIdx) {
  for (int i = begIdx; i < endIdx; i++) {
    T curr = list[i + 1];
    int j;
    for (j = i; j >= begIdx && list[j] > curr; j--) {
      list[j + 1] = list[j];
    }
    list[j + 1] = curr;
  }
}

#endif
