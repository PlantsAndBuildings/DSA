/**
 * \file quick_sort.cpp
 *
 * Quick sort implementation for specialized types
 */
#include "quick_sort.hpp"

/**
 * \brief \ref sorting::QuickSorter_t::sort() "sort()" function
 * specialization for `float` data type
 *
 * Calls private method \ref sorting::QuickSorter_t::sortUtilNumeric
 * "sortUtilNumeric()"
 *
 * \param list vector of `float`s to be sorted
 */
template <> void sorting::QuickSorter_t<float>::sort(vector<float> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<float>::sortUtilNumeric(list, 0, list.size() - 1);
}

/**
 * \brief \ref sorting::QuickSorter_t::sort() "sort()" function
 * specialization for `double` data type
 *
 * Calls private method \ref sorting::QuickSorter_t::sortUtilNumeric
 * "sortUtilNumeric()"
 *
 * \param list vector of `double`s to be sorted
 */
template <> void sorting::QuickSorter_t<double>::sort(vector<double> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<double>::sortUtilNumeric(list, 0, list.size() - 1);
}

/**
 * \brief \ref sorting::QuickSorter_t::sort() "sort()" function
 * specialization for `int` data type
 *
 * Calls private method \ref sorting::QuickSorter_t::sortUtilNumeric
 * "sortUtilNumeric()"
 *
 * \param list vector of `int`s to be sorted
 */
template <> void sorting::QuickSorter_t<int>::sort(vector<int> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<int>::sortUtilNumeric(list, 0, list.size() - 1);
}

/**
 * \brief \ref sorting::QuickSorter_t::sort() "sort()" function
 * specialization for `long` data type
 *
 * Calls private method \ref sorting::QuickSorter_t::sortUtilNumeric
 * "sortUtilNumeric()"
 *
 * \param list vector of `long`s to be sorted
 */
template <> void sorting::QuickSorter_t<long>::sort(vector<long> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<long>::sortUtilNumeric(list, 0, list.size() - 1);
}

/**
 * \brief \ref sorting::QuickSorter_t::sort() "sort()" function
 * specialization for `long long` data type
 *
 * Calls private method \ref sorting::QuickSorter_t::sortUtilNumeric
 * "sortUtilNumeric()"
 *
 * \param list vector of `long long`s to be sorted
 */
template <>
void sorting::QuickSorter_t<long long>::sort(vector<long long> &list) {
  if (list.empty())
    return;
  sorting::QuickSorter_t<long long>::sortUtilNumeric(list, 0, list.size() - 1);
}
