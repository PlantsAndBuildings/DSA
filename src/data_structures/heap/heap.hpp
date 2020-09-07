#ifndef HEAP_HPP
#define HEAP_HPP

#include "heap_type.hpp"
#include <vector>

/**
 * \brief Heap data structure
 *
 * Heap is a binary tree based data structure. A complete binary tree is one
 * where all the levels (except perhaps the last) are completely filled and all
 * the nodes are as far left as possible. A heap is a complete binary tree which
 * satisfies the Heap Property (defined below).
 *
 * **Heap Property**: A complete binary tree is said to satisfy the heap
 * property if for any node, all the nodes in the subtree rooted at that node
 * are less than the value at that node. In this case the heap is said to be a
 * max heap. Similarly, if for any node, all the nodes in the subtree rooted at
 * that node are greater than the value at that node - then the heap is said to
 * be a min heap.
 *
 * Heaps are commonly used to implement the heap-sort algorithm and priority
 * queues
 *
 * Even though heaps are logically a nonlinear data structure, our
 * implementation uses a linear vector to store the heap nodes. Each element of
 * the vector represents a node in the heap. An element at position `i` has it's
 * left child at position `2*i+1` and right child at `2*i+2`. This
 * representation works because heaps are complete binary trees. Of course, this
 * representation is abstracted away from the users of this class.
 *
 * For complete details about heaps, and how they're represented using
 * arrays/vectors - please refer any standard text on data structures
 * (preferably Introduction to Algorithms by Cormen et al)
 *
 * \tparam T Data type of the elements to be stored in the heap
 *
 * \see sorting::HeapSorter_t
 */
template <typename T> class Heap {
public:
  /**
   * \brief default Heap constructor
   *
   * Initializes an empty max-heap
   */
  Heap();

  /**
   * \brief Heap constructor
   *
   * Initializes a max-heap using the input param `list`
   *
   * \param list vector to be used to initialize the heap
   */
  Heap(std::vector<T> &list);

  /**
   * \brief Heap constructor
   *
   * Initializes a heap using the input param `list` and heap type `heapType`
   *
   * \param list vector to be used to initialize the heap
   *
   * \param heapType type of heap (\ref HeapType::MaxHeap "Max Heap" or \ref
   * HeapType::MinHeap "Min Heap")
   */
  Heap(std::vector<T> &list, HeapType heapType);

  /**
   * \brief default destructor
   */
  ~Heap();

  /**
   * \brief type of heap (\ref HeapType::MaxHeap "Max Heap" or \ref
   * HeapType::MinHeap "Min Heap")
   */
  HeapType type;

  /**
   * \brief number of elements in the heap
   *
   * \return size of heap
   */
  unsigned int size();

  /**
   * \brief Insert a new element into the heap
   *
   * \param elem New element to be inserted
   */
  void insert(T &elem);

  /**
   * \brief View the element at the top of the heap (that is, at the root node)
   *
   * \return value of the root node of the heap
   */
  T &top();

  /**
   * \brief Remove the element at the top of the heap
   *
   * This is a generic implementation. Specific implementations (eg. for numeric
   * types like `int`, `float` etc) can be found in heap.cpp
   *
   * \return Value at the top of the heap
   */
  T extractTop();

  /**
   * \brief Check if the heap is empty
   *
   * \return `true` if heap is empty, `false` otherwise
   */
  bool empty();

private:
  /**
   * \brief Internal typedef defined for indexes in the `heap` vector
   */
  typedef unsigned int idx_t;

  /**
   * \brief Vector which will store the heap nodes
   */
  std::vector<T> heap;

  /**
   * \brief Size of the heap
   */
  unsigned int sz;

  /**
   * \brief Heapify method to restore the heap property after a node has been
   * modified.
   *
   * Please refer Introduction to Algorithms by Cormen et al for complete
   * details about heapify. This is an implementation for generic data type. It
   * is used internally by \ref Heap::buildHeap and \ref Heap::extractTop.
   *
   * \param idx heap node to run heapify on
   */
  void heapify(typename Heap<T>::idx_t idx);

  /**
   * \brief Heapify method to restore the heap property after a node has been
   * modified.
   *
   * Please refer Introduction to Algorithms by Cormen et al for complete
   * details about heapify. This is an implementation for numeric data types
   * (ie. `int`s, `float`s etc). It is used internally by \ref
   * Heap::buildHeapNumeric and \ref Heap::extractTopNumeric.
   *
   * \param idx heap node to run heapify on
   */
  void heapifyNumeric(typename Heap<T>::idx_t idx);

  /**
   * \brief This function initializes the heap from a given input vector when
   * the Heap class is instantiated
   *
   * Called from the \ref Heap::Heap(), \ref Heap::Heap(std::vector), \ref
   * Heap::Heap(std::vector, HeapType) constructors. This function implements
   * the build heap process for a generic type. Please refer to the specialized
   * versions in heap.cpp for specific implementation for numeric types etc.
   *
   */
  void buildHeap();

  /**
   * \brief buildHeap() for numeric data types
   *
   * Please see specialiations of buildHeap() present in heap.cpp
   *
   */
  void buildHeapNumeric();

  /**
   * \brief utility method to get the index of left child for any given node
   * index
   *
   * \param idx index of node whose left child is required
   *
   * \return index of left child
   */
  inline typename Heap<T>::idx_t left(typename Heap<T>::idx_t idx);

  /**
   * \brief utility method to get the index of right child for any given node
   * index
   *
   * \param idx index of node whose right child is required
   *
   * \return index of right child
   */
  inline typename Heap<T>::idx_t right(typename Heap<T>::idx_t idx);

  /**
   * \brief utility method to get the index of parent node for any given node
   * index
   *
   * \param idx index of node whose parent is required
   *
   * \return index of parent node
   */
  inline typename Heap<T>::idx_t parent(typename Heap<T>::idx_t idx);

  /**
   * \brief utilty function used by heapify()
   *
   * heapify() procedure works by moving a out-of-place node in the heap down a
   * subtree till it reaches a state where all nodes of the heap satisfy the
   * heap property again. This method compares the node present at index `idx`
   * and it's children; and returns the index of the node having max/min value
   * (depending on whether the heap is a max heap or a min heap). This min/max
   * node must now be propagated to index `idx` (if it already isn't there)
   *
   * \param idx Node index at which to find the min/max considering its children
   */
  typename Heap<T>::idx_t findIdxToBePropagated(typename Heap<T>::idx_t);

  /**
   * \brief findIdxToBePropagated() implementation for numeric types
   *
   * \param idx Node index at which to find the min/max considering its children
   */
  typename Heap<T>::idx_t
      findIdxToBePropagatedForNumericHeap(typename Heap<T>::idx_t);

  /**
   * \brief extractTop() implementation for numeric types
   */
  T extractTopForNumericHeap();

  /** \brief constant representing top index of the heap */
  const static Heap<T>::idx_t TOP = 0;
};

#include "heap.tpp"

#endif
