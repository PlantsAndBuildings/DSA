#ifndef QUICK_SORT_TPP
#define QUICK_SORT_TPP

template <typename T> void QuickSorter_t<T>::sort(vector<T> &list) {
  LOG_ERROR << "Sorting vector<T> using quick sort not implemented!";
}

template <typename T>
void QuickSorter_t<T>::sortUtilNumeric(vector<T> &list, int begIdx,
                                       int endIdx) {
  // N denotes the size of the range that needs to be sorted
  int N = endIdx - begIdx + 1;

  // Handle base cases
  if (N <= 0 || N == 1)
    return;

  // Pivot element is selected randomly from the range. This is some boilerplate
  // code for generating the pivot randomly
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(begIdx, endIdx);

  // Select the pivot randomly from the range list[begIdx..endIdx]
  int pivotIdx = distrib(gen);
  T pivot = list[pivotIdx];
  LOG_DEBUG << "Pivot elem: " << pivot;

  // We want to partition the list[begIdx..endIdx] as follows:
  // 1. list[begIdx .. smallIdx] < pivot
  // 2. list[smallIdx+1 .. bigIdx - 1] == pivot
  // 3. list[bigIdx .. endIdx] > pivot

  // Initialize smallIdx and bigIdx
  int smallIdx = begIdx - 1;
  int bigIdx = endIdx + 1;

  // We will use idx to iterate over the array range
  int idx = begIdx;

  // idx is used to iterate through list[begIdx..endIdx]
  // At every iteration, we will check whether list[idx] is less than; greater
  // than; or equal to the pivot element All the list elements within the range
  // that are less than the pivot element will be moved to the beginning of the
  // range. Ie. list[begIdx..smallIdx] will contain all the elements in range
  // smaller than the pivot Similarly, all the list elements within the range
  // that are greater than the pivot will be moved to the end of the range. Ie.
  // list[bigIdx..endIdx] will contain all the elements in the range greater
  // than the pivot list[smallIdx+1..bigIdx-1] will contain list elements ==
  // pivot Once we have achieved the partitioning descibed above, we can run
  // this method recursively on subranges list[begIdx..smallIdx] and
  // list[bigIdx..endIdx]
  while (bigIdx > smallIdx && bigIdx >= begIdx && smallIdx <= endIdx &&
         idx < bigIdx) {
    if (list[idx] < pivot) {
      // swap list[idx] and list[smallIdx + 1]
      T tmp = list[idx];
      list[idx] = list[smallIdx + 1];
      list[smallIdx + 1] = tmp;

      // increment smallIdx
      smallIdx++;

      // increment idx
      idx++;
    } else if (list[idx] > pivot) {
      // swap list[idx] and list[bigIdx - 1]
      T tmp = list[idx];
      list[idx] = list[bigIdx - 1];
      list[bigIdx - 1] = tmp;

      // decrement bigIdx
      bigIdx--;
    } else {
      // increment only idx
      idx++;
    }
  }
  // At the end of the above loop:
  // 1. list[begIdx .. smallIdx] < pivot
  // 2. list[smallIdx+1 .. bigIdx - 1] == pivot
  // 3. list[bigIdx .. endIdx] > pivot
  std::vector<T> range(list.begin() + begIdx, list.begin() + endIdx + 1);
  LOG_DEBUG << "Range after partitioning: " << logging::str(range);

  // Run quicksort on list[begIdx .. smallIdx] and list[bigIdx .. endIdx]
  this->sortUtilNumeric(list, begIdx, smallIdx);
  this->sortUtilNumeric(list, bigIdx, endIdx);
}

#endif
