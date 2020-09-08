#include "../src/data_structures/heap/heap.hpp"
#include "../src/data_structures/heap/heap_type.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <boost/log/trivial.hpp>
#include <vector>

void heapInts() {
  std::vector<int> v = {1, 2, 3};
  Heap<int> h(v, HeapType::MaxHeap);
}

void heapFloats() {
  std::vector<float> v = {2.65, 1.23, 3.001};
  Heap<float> h(v, HeapType::MinHeap);
}

void heapStrings() {
  std::vector<std::string> v = {"Daivik", "Is", "Amazing"};
  Heap<std::string> h(v, HeapType::MaxHeap);
}

int main() {
  logging::loggerInit("DEBUG");
  heapInts();
  heapFloats();
  heapStrings();
  return 0;
}
