#ifndef SORTER_FACTORY_TPP
#define SORTER_FACTORY_TPP

template <typename T>
sorting::Sorter<T>
sorting::SorterFactory::getSorter(sorting::SortingAlgorithm sortingAlgorithm) {
  Sorter_t<T> *sorter;
  switch (sortingAlgorithm) {
  case sorting::SortingAlgorithm::MergeSort:
    sorter = new MergeSorter_t<T>();
    break;
  case sorting::SortingAlgorithm::BubbleSort:
    break;
  }
  return *sorter;
}

template <typename T>
void sorting::SorterFactory::deleteSorter(sorting::Sorter<T> &sorter) {
  delete &sorter;
}

#endif
