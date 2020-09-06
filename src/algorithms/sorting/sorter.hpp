#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>

using std::vector;

/**
 * Namespace to contain sorters and sorter factory
 */
namespace sorting {

/**
 * \brief Abstract base class for various sorting implementations.
 *
 * Various concrete sorter implementations such as \ref sorting::BubbleSorter_t
 * "BubbleSorter" and \ref sorting::MergeSorter_t "MergeSorter" implement the
 * method in this class. A \ref sorting::SorterFactory "SorterFactory" is used
 * to generate objects of this type. A sorter requires (as template argument) a
 * data type - indicating the type of data it is expected to sort. For example,
 * a \ref sorting::MergeSorter_t "MergeSorter<int>" will be used to sort a
 * vector of `int`s via the Merge Sort algorithm
 *
 * \tparam T data type of elements to be sorted
 */
template <typename T> class Sorter_t {
public:
  /**
   * \brief Sort virtual method
   *
   * This is implemented in various concrete sorter child classes like
   * \ref sorting::BubbleSorter_t "BubbleSorter", \ref sorting::HeapSorter_t
   * "HeapSorter" etc. The passed vector is expected to be sorted in place.
   *
   * \param list vector to be sorted
   */
  virtual void sort(vector<T> &) = 0;

  virtual ~Sorter_t(){};
};

//! When \ref sorting::SorterFactory "SorterFactory" is invoked to create a new
//! concrete sorter, we want to return a reference rather than the object
//! itself. This is a convenience typedef for that purpose.
template <typename T> using Sorter = Sorter_t<T> &;

} // namespace sorting

#endif
