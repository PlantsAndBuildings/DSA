cmake_minimum_required(VERSION 3.10)

# set project name
project(dsa-implementations)

# set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# some useful paths in the project tree
set(SORTING_ALGORITHMS_BASE_DIR ${PROJECT_SOURCE_DIR}/src/algorithms/sorting)
set(EXAMPLES_BASE_DIR ${PROJECT_SOURCE_DIR}/examples)
set(UTILS_BASE_DIR ${PROJECT_SOURCE_DIR}/utils)

# find boost logging and testing
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_DYN_LINK)

find_package(Boost 1.65 REQUIRED COMPONENTS log unit_test_framework)

# add executables
add_executable(merge_sort_basic ${EXAMPLES_BASE_DIR}/merge_sort_basic.cpp ${SORTING_ALGORITHMS_BASE_DIR}/merge_sort/merge_sort.cpp ${UTILS_BASE_DIR}/boost/logging_utils.cpp)
target_link_libraries(merge_sort_basic ${Boost_SYSTEM_LIBRARY} ${Boost_LOG_LIBRARY} -lpthread)
