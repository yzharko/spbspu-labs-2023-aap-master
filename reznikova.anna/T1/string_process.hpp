#ifndef STRING_PROCESS_HPP
#define STRING_PROCESS_HPP
#include <string>
#include "base-types.hpp"

namespace reznikova
{
  double getNextValue(std::string& line);
  point_t getPointFromString(std::string& line);
}

#endif
