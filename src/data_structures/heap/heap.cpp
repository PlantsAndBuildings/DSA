#include "heap.hpp"

template <> void Heap<int>::buildHeap() { this->buildHeapNumeric(); }

template <> void Heap<float>::buildHeap() { this->buildHeapNumeric(); }

template <> void Heap<double>::buildHeap() { this->buildHeapNumeric(); }

template <> void Heap<long>::buildHeap() { this->buildHeapNumeric(); }

template <> void Heap<long long>::buildHeap() { this->buildHeapNumeric(); }

template <> int Heap<int>::extractTop() {
  return this->extractTopForNumericHeap();
}

template <> float Heap<float>::extractTop() {
  return this->extractTopForNumericHeap();
}

template <> double Heap<double>::extractTop() {
  return this->extractTopForNumericHeap();
}

template <> long Heap<long>::extractTop() {
  return this->extractTopForNumericHeap();
}

template <> long long Heap<long long>::extractTop() {
  return this->extractTopForNumericHeap();
}
