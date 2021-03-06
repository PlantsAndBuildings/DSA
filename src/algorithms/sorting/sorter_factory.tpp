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
  case sorting::SortingAlgorithm::SelectionSort:
    sorter = new SelectionSorter_t<T>();
    break;
  case sorting::SortingAlgorithm::BubbleSort:
    sorter = new BubbleSorter_t<T>();
    break;
  case sorting::SortingAlgorithm::InsertionSort:
    sorter = new InsertionSorter_t<T>();
    break;
  case sorting::SortingAlgorithm::HeapSort:
    sorter = new HeapSorter_t<T>();
    break;
  case sorting::SortingAlgorithm::QuickSort:
    sorter = new QuickSorter_t<T>();
    break;
  }
  return *sorter;
}

template <typename T>
void sorting::SorterFactory::deleteSorter(sorting::Sorter<T> &sorter) {
  delete &sorter;
}

#endif
