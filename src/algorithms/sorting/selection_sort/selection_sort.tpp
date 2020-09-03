#ifndef SELECTION_SORT_TPP
#define SELECTION_SORT_TPP

#include <limits>

template <typename T>
void sorting::SelectionSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using selection sort not implemented!";
}

template <typename T>
void sorting::SelectionSorter_t<T>::sortUtilNumeric(vector<T> &list,
                                                    unsigned int begIdx,
                                                    unsigned int endIdx) {
  for (unsigned int i = begIdx; i <= endIdx; i++) {
    for (unsigned int j = i + 1; j <= endIdx; j++) {
      if (list[i] > list[j]) {
        // swap the values
        T tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
      }
    }
  }
}

#endif
