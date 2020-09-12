## Data Structures & Algorithms

This repository contains my implementations of some standard data structures and algorithms which can be found in any introductory text on the subject. Personally, I refer extensively to "Introduction to Algorithms" by Cormen et al (CLRS henceforth) - as a result of which one may find that implementations provided here draw heavily from the explanations and intuitions given in CLRS. My recommendation to anyone looking at the code in this repository would be to go through the relevant sections in CLRS first.

Primarily, this repository is intended to serve as a single, complete reference for me to revisit in the future and refresh my understanding of various DSA topics. As such, the code is heavily documented and written in a way that favors readability.

Additionally, I also want to place some emphasis on good design and "the C++ way to do things" - that is, to keep in mind and adhere to best coding practices, standards and tools as much as possible. The idea is to have features that you would expect any library implementation of these algorithms and data structures to have. Generics is a good example - we want our data structures to be implemented in a way that they can store any data type; or we want our sorting algorithms to be able to sort inputs over a wide array of data types such as `int`, `float`, `string` etc. Generics are something that one would expect say, an STL implementation of sorting, to have. So yeah; generics, well designed class heirarchies and design patterns, an API reference documentation, a `cmake` based build and test workflow, unit tests - these are all auxiliary goals that I hope to achieve in this repository.

### API Documentation

Complete API documentation for the project can be found [here](https://plantsandbuildings.github.io/DSA/).

### System Requirements (for Building and Running the Project)

The code is this repository has been tested on a 64 bit (x86) machine running Ubuntu 18.04. The code should build and run on most architectures and recent versions/distributions of Linux. The following tools will, however, need to be installed in order to build and run the code examples and tests:
* gcc >= 7.5
* CMake >= 3.10
* GNU Make >= 4.1
* Boost log and unit test libaries (version >= 1.65)
* Doxygen >= 1.9

### Steps to Build and Run Tests and Examples

Given that the above tools and libraries are installed, the project can be built as follows:

**Step 1:** Cloning the repository
``` bash
cd /some/convenient/location
git clone https://github.com/PlantsAndBuildings/DSA.git
cd DSA/
```

**Step 2:** Creating build directory and configuring the build
``` bash
mkdir build && cd build
cmake ../
```

**Step 3:** Building the project
``` bash
make
```
**Step 4:** Running the examples and tests

If all goes well, you should see all the targets being built successfully. Binary executables for the example programs are written to the `build/bin/` directory. Examples can be run as follows:

``` bash
bin/heap_sort_basic
```

Similarly, the executables for the tests are written to `build/bin/test/`. A specific test can be run by running its executable as follows:

``` bash
bin/test/bubble_sort_test
```

All the tests can be run at once by executing:
``` bash
ctest
```

**Step 5 (Optional):** Generating the API docs locally

``` bash
doxygen Doxyfile
```
The docs should be accessible by navigating to `file:///some/convenient/location/DSA/docs/index.html` in a web browser


