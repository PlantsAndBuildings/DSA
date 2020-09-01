#ifndef MERGE_SORT
#define MERGE_SORT

#include "../sorter.hpp"

namespace sorting {
class MergeSorter_t : public Sorter_t {
  public:
    void sort(vector<long long>&);

    void sort(vector<int>&);
};

typedef MergeSorter_t& MergeSorter;
}

#endif
