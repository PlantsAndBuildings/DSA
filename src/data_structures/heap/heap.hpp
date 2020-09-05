#ifndef HEAP_HPP
#define HEAP_HPP

#include "heap_type.hpp"
#include <vector>

template <typename T> class Heap {
public:
  Heap();
  Heap(std::vector<T> &);
  Heap(std::vector<T> &, HeapType);
  ~Heap();
  HeapType type;
  unsigned int size();
  void insert(T &);
  T &top();
  T extractTop();
  bool empty();

private:
  typedef unsigned int idx_t;
  std::vector<T> heap;
  unsigned int sz;
  void heapify(unsigned int);
  void heapifyNumeric(unsigned int);
  void buildHeap();
  void buildHeapNumeric();
  inline typename Heap<T>::idx_t left(typename Heap<T>::idx_t);
  inline typename Heap<T>::idx_t right(typename Heap<T>::idx_t);
  inline typename Heap<T>::idx_t parent(typename Heap<T>::idx_t);
  typename Heap<T>::idx_t findIdxToBePropagated(typename Heap<T>::idx_t);
  typename Heap<T>::idx_t
      findIdxToBePropagatedForNumericHeap(typename Heap<T>::idx_t);
  T extractTopForNumericHeap();

  const static Heap<T>::idx_t TOP = 0;
};

#include "heap.tpp"

#endif
