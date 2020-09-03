#ifndef LOGGING_UTILS
#define LOGGING_UTILS

#include <iostream>
#include <vector>
#include <boost/log/trivial.hpp>

#define LOG_TRACE BOOST_LOG_TRIVIAL(trace)
#define LOG_DEBUG BOOST_LOG_TRIVIAL(debug)
#define LOG_INFO BOOST_LOG_TRIVIAL(info)
#define LOG_ERROR BOOST_LOG_TRIVIAL(error)

namespace logging {
  void loggerInit();
  void loggerInit(const char*);
  std::string str(vector<int>&);
  std::string str(vector<double>&);
  std::string str(vector<std::string>&);
}


#endif
