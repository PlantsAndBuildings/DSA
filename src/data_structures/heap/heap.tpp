#ifndef HEAP_TPP
#define HEAP_TPP

#include "../../../utils/boost/logging_utils.hpp"
#include "heap.hpp"
#include "heap_type.hpp"
#include <vector>

template <typename T> Heap<T>::Heap() {
  this->heap = std::vector<T>();
  this->type = HeapType::MaxHeap;
  this->sz = 0;
}

template <typename T> Heap<T>::~Heap() {}

template <typename T> Heap<T>::Heap(std::vector<T> &list) {
  LOG_DEBUG << "Input list: " << logging::str(list);
  this->heap = std::vector<T>(list);
  this->type = HeapType::MaxHeap;
  this->sz = this->heap.size();
  LOG_DEBUG << "HeapType: " << this->type;
  LOG_DEBUG << "Heap Size: " << this->sz;
  buildHeap();
  LOG_DEBUG << "buildHeap() completed: " << logging::str(heap);
}

template <typename T> Heap<T>::Heap(std::vector<T> &list, HeapType type) {
  LOG_DEBUG << "Input list: " << logging::str(list);
  this->heap = std::vector<T>(list);
  this->type = type;
  this->sz = this->heap.size();
  LOG_DEBUG << "HeapType: " << this->type;
  LOG_DEBUG << "Heap Size: " << this->sz;
  buildHeap();
  LOG_DEBUG << "buildHeap() completed: " << logging::str(heap);
}

template <typename T> typename Heap<T>::idx_t Heap<T>::size() {
  return this->sz;
}

template <typename T>
inline typename Heap<T>::idx_t Heap<T>::left(typename Heap<T>::idx_t idx) {
  return 2 * idx + 1;
}

template <typename T>
inline typename Heap<T>::idx_t Heap<T>::right(typename Heap<T>::idx_t idx) {
  return 2 * idx + 2;
}

template <typename T>
inline typename Heap<T>::idx_t Heap<T>::parent(typename Heap<T>::idx_t idx) {
  if (idx == 0)
    return 0;
  return (idx - 1) / 2;
}

template <typename T>
typename Heap<T>::idx_t
Heap<T>::findIdxToBePropagated(typename Heap<T>::idx_t idx) {
  typename Heap<T>::idx_t lIdx = left(idx);
  typename Heap<T>::idx_t rIdx = right(idx);

  typename Heap<T>::idx_t idxToBePropagated = idx;

  // Handle case for MaxHeap
  if (type == HeapType::MaxHeap) {
    if (lIdx<this->sz & this->heap[lIdx]> this->heap[idxToBePropagated]) {
      idxToBePropagated = lIdx;
    }
    if (rIdx < this->sz && this->heap[rIdx] > this->heap[idxToBePropagated]) {
      idxToBePropagated = rIdx;
    }
  }

  // Handle case for MinHeap
  if (type == HeapType::MinHeap) {
    if (lIdx < this->sz && this->heap[lIdx] < this->heap[idxToBePropagated]) {
      idxToBePropagated = lIdx;
    }
    if (rIdx < this->sz && this->heap[rIdx] < this->heap[idxToBePropagated]) {
      idxToBePropagated = rIdx;
    }
  }

  return idxToBePropagated;
}

template <typename T>
void Heap<T>::heapifyNumeric(typename Heap<T>::idx_t idx) {
  typename Heap<T>::idx_t idxToBePropagated = findIdxToBePropagated(idx);

  if (idxToBePropagated == idx)
    return;

  // Swap value at idx with value at idxToBePropagated
  T tmp = this->heap[idx];
  this->heap[idx] = this->heap[idxToBePropagated];
  this->heap[idxToBePropagated] = tmp;

  // Call heapfiy on idxToBePropagated
  heapifyNumeric(idxToBePropagated);
}

template <typename T> bool Heap<T>::empty() {
  return this->sz == 0 && this->heap.size() == 0;
}

template <typename T> T &Heap<T>::top() {
  if (!this->empty())
    return this->heap[TOP];
  LOG_ERROR << "Attempting to call top() on empty heap!";
}

template <typename T> void Heap<T>::buildHeap() {
  if (!this->empty()) {
    for (typename Heap<T>::idx_t idx = (this->sz) / 2; idx > 0; idx--) {
      this->heapifyNumeric(idx);
    }
    this->heapifyNumeric(0);
  }
}

#endif
