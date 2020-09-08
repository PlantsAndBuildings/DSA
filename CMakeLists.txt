cmake_minimum_required(VERSION 3.10)

# set project name
project(dsa-implementations)

# set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# some useful paths in the project tree
set(SORTING_ALGORITHMS_BASE_DIR ${PROJECT_SOURCE_DIR}/src/algorithms/sorting)
set(DATA_STRUCTURES_BASE_DIR ${PROJECT_SOURCE_DIR}/src/data_structures)
set(EXAMPLES_BASE_DIR ${PROJECT_SOURCE_DIR}/examples)
set(UTILS_BASE_DIR ${PROJECT_SOURCE_DIR}/utils)
set(TESTS_BASE_DIR ${PROJECT_SOURCE_DIR}/test)

# find boost logging and testing
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# set the directory to place examples executables in
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_definitions(-DBOOST_ALL_DYN_LINK)

find_package(Boost 1.65 REQUIRED COMPONENTS log unit_test_framework)

######### ALGORITHMS

# Add executables for sorting algorithm examples

# Merge Sort
add_executable(merge_sort_basic ${EXAMPLES_BASE_DIR}/merge_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/merge_sort/merge_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(merge_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Heap Sort
add_executable(heap_sort_basic ${EXAMPLES_BASE_DIR}/heap_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/heap_sort/heap_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp ${DATA_STRUCTURES_BASE_DIR}/heap/heap.cpp)
target_link_libraries(heap_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Quick Sort
add_executable(quick_sort_basic ${EXAMPLES_BASE_DIR}/quick_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/quick_sort/quick_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(quick_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Selection Sort
add_executable(selection_sort_basic ${EXAMPLES_BASE_DIR}/selection_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/selection_sort/selection_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(selection_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Bubble Sort
add_executable(bubble_sort_basic ${EXAMPLES_BASE_DIR}/bubble_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/bubble_sort/bubble_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(bubble_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Insertion Sort
add_executable(insertion_sort_basic ${EXAMPLES_BASE_DIR}/insertion_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/insertion_sort/insertion_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(insertion_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

######### DATA STRUCTURES

# Heap
add_executable(heap_basic ${EXAMPLES_BASE_DIR}/heap_basic.cpp ${DATA_STRUCTURES_BASE_DIR}/heap/heap.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(heap_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

enable_testing()

# set the directory to place examples executables in
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test)

# add executables for tests

# Merge Sort
add_executable(merge_sort_test ${TESTS_BASE_DIR}/merge_sort.cpp ${SORTING_ALGORITHMS_BASE_DIR}/merge_sort/merge_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(merge_sort_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Selection Sort
add_executable(selection_sort_test ${TESTS_BASE_DIR}/selection_sort.cpp ${SORTING_ALGORITHMS_BASE_DIR}/selection_sort/selection_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(selection_sort_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Bubble Sort
add_executable(bubble_sort_test ${TESTS_BASE_DIR}/bubble_sort.cpp ${SORTING_ALGORITHMS_BASE_DIR}/bubble_sort/bubble_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(bubble_sort_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

# Insertion Sort
add_executable(insertion_sort_test ${TESTS_BASE_DIR}/insertion_sort.cpp ${SORTING_ALGORITHMS_BASE_DIR}/insertion_sort/insertion_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(insertion_sort_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)

add_test(NAME merge_sort_test COMMAND merge_sort_test)
add_test(NAME selection_sort_test COMMAND selection_sort_test)
add_test(NAME bubble_sort_test COMMAND bubble_sort_test)
add_test(NAME insertion_sort_test COMMAND insertion_sort_test)
