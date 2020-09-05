#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace logging {
void loggerInit() {
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);
}

void loggerInit(const char *level) {
  if (!std::string("DEBUG").compare(level)) {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                        boost::log::trivial::debug);
  } else if (!std::string("INFO").compare(level)) {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                        boost::log::trivial::info);
  } else {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                        boost::log::trivial::info);
  }
}

template <typename T> std::string __str__(std::vector<T> &vec) {
  std::ostringstream oss;
  oss << "[ ";
  if (!vec.empty()) {
    // Convert all but the last element to avoid a trailing ","
    std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(oss, ", "));

    // Now add the last element with no delimiter
    oss << vec.back();
  }
  oss << " ]";
  return oss.str();
}

std::string str(std::vector<int> &vec) { return __str__(vec); }

std::string str(std::vector<float> &vec) { return __str__(vec); }

std::string str(std::vector<double> &vec) { return __str__(vec); }

std::string str(std::vector<long> &vec) { return __str__(vec); }

std::string str(std::vector<long long> &vec) { return __str__(vec); }

std::string str(std::vector<std::string> &vec) { return __str__(vec); }
} // namespace logging
