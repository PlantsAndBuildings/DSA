#ifndef MERGE_SORT_TPP
#define MERGE_SORT_TPP

template <typename T> void sorting::MergeSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using merge sort not implemented!";
}

template <typename T> void sorting::MergeSorter_t<T>::sortUtilNumeric(vector<T>& list, unsigned int begIdx, unsigned int endIdx) {
  if (endIdx <= begIdx) return;
  unsigned int midIdx = (begIdx + endIdx)/2;
  sorting::MergeSorter_t<T>::sortUtilNumeric(list, begIdx, midIdx);
  sorting::MergeSorter_t<T>::sortUtilNumeric(list, midIdx+1, endIdx);
  sorting::MergeSorter_t<T>::mergeUtilNumeric(list, begIdx, midIdx, endIdx);
}

template <typename T> void sorting::MergeSorter_t<T>::mergeUtilNumeric(vector<T>& list, unsigned int begIdx, unsigned int midIdx, unsigned int endIdx) {
  vector<T> first(list.begin() + begIdx, list.begin() + midIdx + 1);
  vector<T> last(list.begin() + midIdx + 1, list.begin() + endIdx + 1);

  unsigned int firstIdx = 0;
  unsigned int lastIdx = 0;
  unsigned int idx = begIdx;

  while (firstIdx < first.size() && lastIdx < last.size() && idx < endIdx + 1) {
    if (first[firstIdx] < last[lastIdx]) {
      list[idx++] = first[firstIdx++];
    } else {
      list[idx++] = last[lastIdx++];
    }
  }

  while (firstIdx < first.size() && idx < endIdx + 1) {
    list[idx++] = first[firstIdx++];
  }

  while (lastIdx < last.size() && idx < endIdx + 1) {
    list[idx++] = last[lastIdx++];
  }
}

#endif
