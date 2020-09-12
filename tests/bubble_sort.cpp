#define BOOST_TEST_MODULE bubble_sort
#include "../src/algorithms/sorting/bubble_sort/bubble_sort.hpp"
#include "../src/algorithms/sorting/sorter.hpp"
#include "../src/algorithms/sorting/sorter_factory.hpp"
#include <boost/test/unit_test.hpp>

struct BubbleSortTestFixture {
  BubbleSortTestFixture()
      : intSorter(sorting::SorterFactory::getSorter<int>(algorithm)),
        floatSorter(sorting::SorterFactory::getSorter<float>(algorithm)) {}

  ~BubbleSortTestFixture() {
    sorting::SorterFactory::deleteSorter(intSorter);
    sorting::SorterFactory::deleteSorter(floatSorter);
  }

  sorting::SortingAlgorithm algorithm = sorting::SortingAlgorithm::BubbleSort;
  sorting::Sorter<int> intSorter;
  sorting::Sorter<float> floatSorter;
};

// TODO: Add bubble sort testcases

/**
 * Trivial Case: Empty vector<int>
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_empty_input_int, BubbleSortTestFixture) {
  vector<int> vInt;
  BOOST_REQUIRE_EQUAL(vInt.size(), 0);
  intSorter.sort(vInt);
  BOOST_REQUIRE_EQUAL(vInt.size(), 0);
}

/**
 * Trivial Case: Empty vector<float>
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_empty_input_float, BubbleSortTestFixture) {
  vector<float> vFloat;
  BOOST_REQUIRE_EQUAL(vFloat.size(), 0);
  floatSorter.sort(vFloat);
  BOOST_REQUIRE_EQUAL(vFloat.size(), 0);
}

/**
 * Trivial Case: vector<int> containing one element
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_trivial_input_int, BubbleSortTestFixture) {
  vector<int> vInt;
  vInt.push_back(7);
  BOOST_REQUIRE_EQUAL(vInt.size(), 1);
  BOOST_REQUIRE_EQUAL(vInt[0], 7);
  intSorter.sort(vInt);
  BOOST_REQUIRE_EQUAL(vInt.size(), 1);
  BOOST_REQUIRE_EQUAL(vInt[0], 7);
}

/**
 * Trivial Case: vector<float> containing one element
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_trivial_input_float,
                        BubbleSortTestFixture) {
  vector<float> vFloat;
  vFloat.push_back((float)2.34);
  BOOST_REQUIRE_EQUAL(vFloat.size(), 1);
  BOOST_REQUIRE_EQUAL(vFloat[0], (float)2.34);
  floatSorter.sort(vFloat);
  BOOST_REQUIRE_EQUAL(vFloat.size(), 1);
  BOOST_REQUIRE_EQUAL(vFloat[0], (float)2.34);
}

/**
 * Small input: vector<int>
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_small_input_int, BubbleSortTestFixture) {
  vector<int> vInt = {5, 23, 230, 123, 1, 3234, 1, -1, -32, 234};
  vector<int> vIntSorted = {-32, -1, 1, 1, 5, 23, 123, 230, 234, 3234};
  BOOST_REQUIRE_EQUAL(vInt.size(), 10);
  intSorter.sort(vInt);
  BOOST_REQUIRE_EQUAL(vInt.size(), 10);
  BOOST_REQUIRE_EQUAL_COLLECTIONS(vInt.begin(), vInt.end(), vIntSorted.begin(),
                                  vIntSorted.end());
}

/**
 * Small input: vector<float>
 */
BOOST_FIXTURE_TEST_CASE(bubble_sort_small_input_float, BubbleSortTestFixture) {
  vector<float> vFloat = {5.01, 23.97, 230.1234, 123.89, 1.37, 3234.444, 1.556, -1.2, -32, 234};
  vector<float> vFloatSorted = {-32, -1.2, 1.37, 1.556, 5.01, 23.97, 123.89, 230.1234, 234, 3234.444};
  BOOST_REQUIRE_EQUAL(vFloat.size(), 10);
  floatSorter.sort(vFloat);
  BOOST_REQUIRE_EQUAL(vFloat.size(), 10);
  BOOST_REQUIRE_EQUAL_COLLECTIONS(vFloat.begin(), vFloat.end(),
                                  vFloatSorted.begin(), vFloatSorted.end());
}
