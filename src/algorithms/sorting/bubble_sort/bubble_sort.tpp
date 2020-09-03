#ifndef BUBBLE_SORT_TPP
#define BUBBLE_SORT_TPP

#include <limits>

template <typename T> void sorting::BubbleSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using bubble sort not implemented!";
}

template <typename T>
void sorting::BubbleSorter_t<T>::sortUtilNumeric(vector<T> &list,
                                                 unsigned int begIdx,
                                                 unsigned int endIdx) {
  for (unsigned int i = begIdx; i <= endIdx; i++) {
    for (unsigned int j = begIdx; j <= endIdx - 1; j++) {
      if (list[j] > list[j + 1]) {
        // swap the values
        T tmp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = tmp;
      }
    }
  }
}

#endif
