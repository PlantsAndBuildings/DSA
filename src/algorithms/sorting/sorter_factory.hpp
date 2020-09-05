#ifndef SORTER_FACTORY_HPP
#define SORTER_FACTORY_HPP

#include "bubble_sort/bubble_sort.hpp"
#include "heap_sort/heap_sort.hpp"
#include "insertion_sort/insertion_sort.hpp"
#include "merge_sort/merge_sort.hpp"
#include "quick_sort/quick_sort.hpp"
#include "selection_sort/selection_sort.hpp"
#include "sorter.hpp"
#include "sorting_algorithm.hpp"
#include <iostream>
#include <string>

using std::string;

namespace sorting {
/**
 * \brief Factory class for creating sorter objects
 *
 * Defined as final since this should not be extended
 */
class SorterFactory final {
public:
  /**
   * \brief Factory method to create a new sorter object according to the
   * algorithm provided in the argument
   *
   * Note that this function returns a reference to the appropriate sorter -
   * rather than a \ref sorting::Sorter_t "Sorter_t" object. This is done for
   * the obvious reason that we prefer passing around references rather than
   * large bulky objects. If we look at \ref sorter.hpp we find that a
   * convenience typedef `Sorter<T>` has been defined specifically for this
   * purpose.
   *
   * \tparam T type of data that the sorter is expected to perform its
   * processing on
   *
   * \param sortingAlgorithm Based on this parameter, a reference to the
   * appropriate concrete \ref sorting::Sorter_t "Sorter" object is returned
   *
   * \return Reference to a concrete sorter type
   *
   * \see sorting::Sorter_t
   * \see sorting::Sorter
   */
  template <typename T>
  static Sorter<T> getSorter(SortingAlgorithm sortingAlgorithm);

  template <typename T> static void deleteSorter(Sorter<T> &);
};
} // namespace sorting

#include "sorter_factory.tpp"

#endif
