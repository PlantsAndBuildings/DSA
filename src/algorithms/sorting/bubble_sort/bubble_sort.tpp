#ifndef BUBBLE_SORT_TPP
#define BUBBLE_SORT_TPP

#include <limits>

template <typename T> void sorting::BubbleSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using bubble sort not implemented!";
}

template <typename T>
void sorting::BubbleSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                                 int endIdx) {
  for (int i = begIdx; i <= endIdx; i++) {
    for (int j = begIdx; j <= endIdx - 1; j++) {
      // Compare adjacent elements
      if (list[j] > list[j + 1]) {
        // Swap the values if they're in the wrong order
        T tmp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = tmp;
      }
    }
  }
}

#endif
