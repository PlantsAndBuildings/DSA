/**
 * \file heap_basic.cpp
 * \brief Example program for heap operations using different data types
 * \see Heap
 */
#include "../src/data_structures/heap/heap.hpp"
#include "../src/data_structures/heap/heap_type.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <boost/log/trivial.hpp>
#include <vector>

/**
 * Example: max heap of ints
 */
void heapInts() {
  std::vector<int> v = {1, 2, 3};
  Heap<int> h(v, HeapType::MaxHeap);
}

/**
 * Example: min heap of floats
 */
void heapFloats() {
  std::vector<float> v = {2.65, 1.23, 3.001};
  Heap<float> h(v, HeapType::MinHeap);
}

/**
 * Example: max heap of strings
 */
void heapStrings() {
  std::vector<std::string> v = {"Daivik", "Is", "Amazing"};
  Heap<std::string> h(v, HeapType::MaxHeap);
}

/**
 * Driver function
 */
int main() {
  logging::loggerInit("DEBUG");
  heapInts();
  heapFloats();
  heapStrings();
  return 0;
}
