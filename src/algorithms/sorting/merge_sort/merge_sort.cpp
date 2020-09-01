#include "merge_sort.hpp"
#include <iostream>

using std::cout;
using std::endl;
using sorting::MergeSorter_t;

template <>
void MergeSorter_t<long long>::sort(vector<long long>& list) {
  sort(list);
}

template <>
void MergeSorter_t<int>::sort(vector<int>& list) {
  cout << "Sorting a vector<int> using merge sort!" << endl;
}

// template <>
// void MergeSorter_t<std::string>::sort(vector<std::string>& list) {
//   cout << "Sorting a vector<std::string> using merge sort!" << endl;
// }

// template <typename T>
// void MergeSorter_t<T>::sort(vector<T>& list) {
//   cout << "Sorting a vector<T> using merge sort!" << endl;
// }
