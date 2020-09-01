#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>

using std::vector;

namespace sorting {
class Sorter_t {
  public:
    virtual void sort(vector<long long>&) = 0;

    virtual void sort(vector<int>&) = 0;

    virtual ~Sorter_t() {};

};

typedef Sorter_t& Sorter;
}

#endif
