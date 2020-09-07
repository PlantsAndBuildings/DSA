/**
 * \file heap.cpp
 *
 * Heap implementation for specialized types
 */
#include "heap.hpp"

/**
 * \brief \ref Heap::buildHeap() "buildHeap()" function specialization for `int`
 * data type
 *
 * Calls private method \ref Heap::buildHeapNumeric "buildHeapNumeric()"
 */
template <> void Heap<int>::buildHeap() { this->buildHeapNumeric(); }

/**
 * \brief \ref Heap::buildHeap() "buildHeap()" function specialization for
 * `float` data type
 *
 * Calls private method \ref Heap::buildHeapNumeric "buildHeapNumeric()"
 */
template <> void Heap<float>::buildHeap() { this->buildHeapNumeric(); }

/**
 * \brief \ref Heap::buildHeap() "buildHeap()" function specialization for
 * `double` data type
 *
 * Calls private method \ref Heap::buildHeapNumeric "buildHeapNumeric()"
 */
template <> void Heap<double>::buildHeap() { this->buildHeapNumeric(); }

/**
 * \brief \ref Heap::buildHeap() "buildHeap()" function specialization for
 * `long` data type
 *
 * Calls private method \ref Heap::buildHeapNumeric "buildHeapNumeric()"
 */
template <> void Heap<long>::buildHeap() { this->buildHeapNumeric(); }

/**
 * \brief \ref Heap::buildHeap() "buildHeap()" function specialization for `long
 * long` data type
 *
 * Calls private method \ref Heap::buildHeapNumeric "buildHeapNumeric()"
 */
template <> void Heap<long long>::buildHeap() { this->buildHeapNumeric(); }

/**
 * \brief \ref Heap::extractTop() "extractTop()" function specialization for
 * `int` data type
 *
 * Calls private method \ref Heap::extractTopNumeric "extractTopNumeric()"
 */
template <> int Heap<int>::extractTop() {
  return this->extractTopForNumericHeap();
}

/**
 * \brief \ref Heap::extractTop() "extractTop()" function specialization for
 * `float` data type
 *
 * Calls private method \ref Heap::extractTopNumeric "extractTopNumeric()"
 */
template <> float Heap<float>::extractTop() {
  return this->extractTopForNumericHeap();
}

/**
 * \brief \ref Heap::extractTop() "extractTop()" function specialization for
 * `double` data type
 *
 * Calls private method \ref Heap::extractTopNumeric "extractTopNumeric()"
 */
template <> double Heap<double>::extractTop() {
  return this->extractTopForNumericHeap();
}

/**
 * \brief \ref Heap::extractTop() "extractTop()" function specialization for
 * `long` data type
 *
 * Calls private method \ref Heap::extractTopNumeric "extractTopNumeric()"
 */
template <> long Heap<long>::extractTop() {
  return this->extractTopForNumericHeap();
}

/**
 * \brief \ref Heap::extractTop() "extractTop()" function specialization for
 * `long long` data type
 *
 * Calls private method \ref Heap::extractTopNumeric "extractTopNumeric()"
 */
template <> long long Heap<long long>::extractTop() {
  return this->extractTopForNumericHeap();
}
