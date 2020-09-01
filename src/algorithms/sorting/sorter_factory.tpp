#ifndef SORTER_FACTORY_TPP
#define SORTER_FACTORY_TPP

template <typename T>
sorting::Sorter<T>
sorting::SorterFactory::getSorter(sorting::SortingAlgorithm sortingAlgorithm) {
  MergeSorter_t<T> *m = new MergeSorter_t<T>();
  std::cout << "getSorter<T>() called!" << std::endl;
  return *m;
}

#endif
