#include "../src/data_structures/heap/heap.hpp"
#include "../src/data_structures/heap/heap_type.hpp"
#include "../utils/boost/logging_utils.hpp"
#include <boost/log/trivial.hpp>
#include <vector>

int main() {
  logging::loggerInit("DEBUG");

  std::vector<int> v = {1, 2, 3};

  Heap<int> h(v, HeapType::MaxHeap);

  return 0;
}
