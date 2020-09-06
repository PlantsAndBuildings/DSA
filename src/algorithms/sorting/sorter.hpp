#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>

using std::vector;
namespace sorting {

template <typename T> class Sorter_t {
public:
  virtual void sort(vector<T> &) = 0;

  virtual ~Sorter_t(){};
};

template <typename T> using Sorter = Sorter_t<T> &;

} // namespace sorting

#endif
