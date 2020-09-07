#ifndef MERGE_SORT_TPP
#define MERGE_SORT_TPP

template <typename T> void sorting::MergeSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using merge sort not implemented!";
}

template <typename T>
void sorting::MergeSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                                int endIdx) {
  // base case
  if (endIdx <= begIdx)
    return;

  // We want to divide the range[begIdx..endIdx] into two enqual halves:
  // list[begIdx..midIdx] and list[midIdx+1..endIdx]
  int midIdx = (begIdx + endIdx) / 2;

  // Sort the first range
  sorting::MergeSorter_t<T>::sortUtilNumeric(list, begIdx, midIdx);

  // Sort the second range
  sorting::MergeSorter_t<T>::sortUtilNumeric(list, midIdx + 1, endIdx);

  // Merge the ranges. This should be done in linear time
  sorting::MergeSorter_t<T>::mergeUtilNumeric(list, begIdx, midIdx, endIdx);
}

template <typename T>
void sorting::MergeSorter_t<T>::mergeUtilNumeric(vector<T> &list, int begIdx,
                                                 int midIdx, int endIdx) {
  // Copy out the ranges into vectors first and last
  vector<T> first(list.begin() + begIdx, list.begin() + midIdx + 1);
  vector<T> last(list.begin() + midIdx + 1, list.begin() + endIdx + 1);

  // firstIdx will iterate over first
  int firstIdx = 0;
  // lastIdx will iterate over last
  int lastIdx = 0;

  // idx will be used to index the result range
  int idx = begIdx;

  while (firstIdx < first.size() && lastIdx < last.size() && idx < endIdx + 1) {
    // Compare values present at first[firstIdx] and last[lastIdx]
    // Place the smaller value at list[idx]
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
