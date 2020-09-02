cmake_minimum_required(VERSION 3.10)

# set project name
project(dsa-implementations)

# set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# some useful paths in the project tree
set(SORTING_ALGORITHMS_BASE_DIR ${PROJECT_SOURCE_DIR}/src/algorithms/sorting)
set(EXAMPLES_BASE_DIR ${PROJECT_SOURCE_DIR}/examples)

# add executables
add_executable(merge_sort_basic ${EXAMPLES_BASE_DIR}/merge_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/merge_sort/merge_sort.cpp)
